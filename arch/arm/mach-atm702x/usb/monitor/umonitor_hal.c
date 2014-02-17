/*********************************************************************************
*                            Module: usb monitor driver
*                (c) Copyright 2003 - 2008, Actions Co,Ld. 
*                        All Right Reserved 
*
* History:        
*      <author>      <time>       <version >    <desc>
*       houjingkun   2011/07/08   1.0         build this file 
********************************************************************************/

/*!
 * \file   umonitor_hal.c
 * \brief  
 *      usb monitor hardware opration api code.
 * \author houjingkun
 * \par GENERAL DESCRIPTION:
 * \par EXTERNALIZED FUNCTIONS:
 *       null
 *
 *  Copyright(c) 2008-2012 Actions Semiconductor, All Rights Reserved.
 *
 * \version 1.0
 * \date  2011/07/08
 *******************************************************************************/
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/regulator/consumer.h>
#include <mach/atc260x/atc260x.h>
#include <mach/hardware.h>

#include "aotg_regs.h"
#include "umonitor_hal.h"

extern unsigned int otgvbus_gpio;

extern struct atc260x_dev *atc260x_dev_handle;
extern int atc260x_auxadc_read(struct atc260x_dev *atc260x, enum atc260x_auxadc input);
extern int atc260x_enable_vbusotg(int on);


void dwc3_set_mode(usb_hal_monitor_t * pdev, int mode)
{
	u32 reg;

	reg = __raw_readl(pdev->io_base + DWC3_GCTL);
	reg &= ~(DWC3_GCTL_PRTCAPDIR(DWC3_GCTL_PRTCAP_OTG));
	reg |= DWC3_GCTL_PRTCAPDIR(mode);
	__raw_writel(reg, pdev->io_base + DWC3_GCTL);
}


static int usb_monitor_vbus_power(usb_hal_monitor_t * pdev, int is_on)
{
  MONITOR_PRINTK("usb_monitor_vbus_power %04x\n", is_on);
	if(is_on){
    atc260x_enable_vbusotg(is_on);
		gpio_set_value_cansleep(otgvbus_gpio, is_on);
	}else{
		gpio_set_value_cansleep(otgvbus_gpio, is_on);
    atc260x_enable_vbusotg(is_on);	
	}	
	return 0;
}

static int usb_get_dc5v_state(usb_hal_monitor_t * pdev)
{
	/* no use. */
	return USB_DC5V_INVALID;
}

static int usb_get_vbus_state(usb_hal_monitor_t * pdev)
{
	int ret = USB_VBUS_INVALID;

	switch (pdev->config->vbus_type) {
   	case UMONITOR_USB_VBUS:
		/* vbus valid. */
		  ret = act_readl(pdev->usbecs) & (1 << USB3_P0_CTL_VBUS_P0);
		  ret = ret ? USB_VBUS_HIGH: USB_VBUS_LOW;
		  break;
   	case UMONITOR_GPIO_VBUS:
   	  break;
   	case UMONITOR_DC5V_VBUS:
      ret = atc260x_auxadc_read(atc260x_dev_handle, ATC260X_AUX_VBUSV);
		  ret = (ret > VBUS_THRESHOLD) ? USB_VBUS_HIGH: USB_VBUS_LOW;
		  break;
	  default:
		  break;
	}
	
	MONITOR_PRINTK("%s state: %u\n", __func__, ret);
	return ret;	
}

static int usb_hardware_init(usb_hal_monitor_t * pdev);
static int usb_get_idpin_state(usb_hal_monitor_t * pdev)
{
	int ret = USB_ID_STATE_INVALID;

	switch (pdev->config->idpin_type) {
	case UMONITOR_USB_IDPIN:
    ret = (act_readl(pdev->usbecs) &
          (1 << USB3_P0_CTL_ID_P0)) ? USB_ID_STATE_DEVICE:USB_ID_STATE_HOST;
		break;
	case UMONITOR_SOFT_IDPIN:
	case UMONITOR_GPIO_IDPIN:
	default:
		break;
	}
	return ret;
}

static unsigned int usb_get_linestates(usb_hal_monitor_t * pdev)
{
	unsigned int ls;

	ls = ((act_readl(pdev->usbecs) & USB3_P0_CTL_LS_P0_MASK) >> USB3_P0_CTL_LS_P0_SHIFT);
	return ls;
}

static int usb_set_dp_500k_15k(usb_hal_monitor_t * pdev, int enable_500k_up,
			       int enable_15k_down)
{
	unsigned int val;
	
	val = act_readl(pdev->usbecs) & (~((1 << USB3_P0_CTL_DPPUEN_P0) |
			(1 << USB3_P0_CTL_DMPUEN_P0) |
			(1 << USB3_P0_CTL_DPPDDIS_P0) |
			(1 << USB3_P0_CTL_DMPDDIS_P0)));
			
	if (enable_500k_up != 0) {
		val |= (1 << USB3_P0_CTL_DPPUEN_P0)|(1 << USB3_P0_CTL_DMPUEN_P0);
	}
	if (enable_15k_down == 0) {
		val |= (1 << USB3_P0_CTL_DPPDDIS_P0)|(1 << USB3_P0_CTL_DMPDDIS_P0);
	}
	
	MONITOR_PRINTK("dpdm is %08x\n", val);
	act_writel(val, pdev->usbecs);	/* 500k up enable, 15k down disable; */
	return 0;	
	
}

static int usb_set_soft_id(usb_hal_monitor_t * pdev, int en_softid,
			   int id_state)
{
	unsigned int val;

	if (pdev->config->idpin_type == UMONITOR_USB_IDPIN) {
		/* ignore soft idpin setting. */
		en_softid = 0;
	}
	val = act_readl(pdev->usbecs);
	if (en_softid != 0) {
		val |= 0x1 << USB3_P0_CTL_SOFTIDEN_P0;	/* soft id enable. */
	} else {
		val &= ~(0x1 << USB3_P0_CTL_SOFTIDEN_P0);	/* soft id disable. */
	}

	if (id_state != 0) {
		val |= (0x1 << USB3_P0_CTL_SOFTID_P0);
	} else {
		val &= ~(0x1 << USB3_P0_CTL_SOFTID_P0);
	}
	act_writel(val, pdev->usbecs);
	return 0;	
}

static int usb_set_soft_vbus(usb_hal_monitor_t * pdev, int en_softvbus, int vbus_state)
{
	unsigned int val;

	if (pdev->config->vbus_type == UMONITOR_USB_VBUS) {
		/* ignore soft vbus setting. */
		en_softvbus = 0;
	}

	val = act_readl(pdev->usbecs);
	if (en_softvbus != 0) {
		val |= 0x1 << USB3_P0_CTL_SOFTVBUSEN_P0;	/* soft id enable. */
	} else {
		val &= ~(0x1 << USB3_P0_CTL_SOFTVBUSEN_P0);	/* soft id disable. */
	}

	if (vbus_state != 0) {
		val |= (0x1 << USB3_P0_CTL_SOFTVBUS_P0);
	}else {
		val &= ~(0x1 << USB3_P0_CTL_SOFTVBUS_P0);
	}
	act_writel(val, pdev->usbecs);
	
	return 0;
}

static void usb_hal_set_cmu_usbpll(usb_hal_monitor_t *pdev, int enable)
{
	if (enable != 0) {
		act_writel(act_readl(pdev->usbpll) | (0x1f), pdev->usbpll);
	} else {
		act_writel(act_readl(pdev->usbpll) & ~(0x1f),pdev->usbpll);
	}
	mdelay(2);
}

/******************************************************************************/
/*!
 * \par  Description:
 *       ��usbģ����г�ʼ������������ʱ�ӣ���λ����usbӲ��ģ�飬��ȷ����λ�ڷ���ǰ���
 * \param[in] void
 * \param[in] void
 * \return    int
 * \retval    0��usbģ���ʼ�����    ��ֵ��usbģ���ʼ��ʧ��
 * \ingroup   hal_usb
 * \par
 * \note
 * 
 *******************************************************************************/
static int usb_hardware_init(usb_hal_monitor_t * pdev)
{  
	act_writel((act_readl(pdev->usbecs) | 0x0000f000), pdev->usbecs);	
	//set VBUS detection threshold,VBUS_DET_THRESHOLD_LEVEL4
	act_writel((act_readl(pdev->usbecs) | VBUS_DET_THRESHOLD_LEVEL4), pdev->usbecs);
  
  MONITOR_PRINTK("usbecs value is %08x------>/n", act_readl(pdev->usbecs));
		
	return 0;
}

/******************************************************************************/
/*!                    
* \par  Description:
*     enable or disable the usb controller
* \param[in]    aotg  contains the controller info
* \param[in]    enable  enable(1) or disable(0) the controller  
* \return       the result  
* \retval           0 sucess 
* \retval           1 failed
* \ingroup      USB_UOC
*******************************************************************************/
static int usb_hal_aotg_enable(usb_hal_monitor_t * pdev, int enable)
{
	if (enable != 0) {
		MONITOR_PRINTK("aotg mon enable\n");
		if (usb_hardware_init(pdev) != 0) {
			return -1;
		}
	} else {
		MONITOR_PRINTK("aotg mon disable\n");		  
	}
	return 0;
}

static int usb_hal_set_mode(usb_hal_monitor_t * pdev, int mode)
{
	if (mode == USB_IN_DEVICE_MOD) {
		act_writel(act_readl(pdev->usbecs) | (0xf << 12), pdev->usbecs);
	}
	if (mode == USB_IN_HOST_MOD) {
		act_writel(act_readl(pdev->usbecs) & ((~0xf) << 12), pdev->usbecs);
	}
	return 0;
}

static void usb_hal_dp_up(usb_hal_monitor_t * pdev)
{
	return;
}

static void usb_hal_dp_down(usb_hal_monitor_t * pdev)
{
	return;
}

static int usb_hal_is_sof(usb_hal_monitor_t * pdev)
{
  return 0;
}

static int usb_hal_enable_irq(struct usb_hal_monitor *pdev, int enable)
{
	return 0;
}

static void usb_hal_debug(usb_hal_monitor_t * pdev)
{
	printk("%s:%d\n", __FILE__, __LINE__);
	printk("pdev->usbecs addr: 0x%x\n\n", pdev->usbecs);
	return;
}

int usb_suspend_or_resume(usb_hal_monitor_t *pdev, int is_suspend)
{
	/* save/reload usbecs when suspend/resume */
	if (is_suspend) {
		pdev->usbecs_val = act_readl(pdev->usbecs);
	}else{
		usb_hardware_init(pdev);
		//act_writel(pdev->usbecs_val, pdev->usbecs);
	}	
	return 0;
}

static void dwc3_controllor_init(usb_hal_monitor_t * pdev)
{
  u32 reg;

	/*USB3 PLL enable*/
	act_writel(act_readl(pdev->usbpll) | (0x1f), pdev->usbpll);
	udelay(1000);
	
  /*USB3 Cmu Reset */
  reg = act_readl(pdev->devrst);
	reg &= ~(USB3_MOD_RST);
	act_writel(reg, pdev->devrst);
	udelay(100);
	
  reg = act_readl(pdev->devrst);
	reg |= (USB3_MOD_RST);
	act_writel(reg, pdev->devrst);
	udelay(100);
	
	/*PLL1 enable*/	
	reg = __raw_readl(pdev->io_base + DWC3_CMU_DEBUG_LDO);
	reg |= CMU_BIAS_EN;
	__raw_writel(reg, pdev->io_base + DWC3_CMU_DEBUG_LDO);

	/*PLL2 enable*/
	reg = (BIST_QINIT(0x3) | EYE_HEIGHT(0x4) | PLL2_LOCK |
			PLL2_RS(0x2) | PLL2_ICP(0x1) | CMU_SEL_PREDIV |
			CMU_DIVX2 | PLL2_DIV(0x17) |PLL2_POSTDIV(0x3) |
			PLL2_PU);	
	__raw_writel(reg, pdev->io_base + DWC3_CMU_PLL2_BISTDEBUG);

	/*USB2 LDO enable*/
	reg = act_readl(pdev->usbecs );
	reg |= (1 << USB3_P0_CTL_PLLLDOEN )|(2 << USB3_P0_CTL_LDOVREFSEL_SHIFT);
	act_writel(reg, pdev->usbecs );
				
	/*dwc3 core reset*/
  reg = __raw_readl(pdev->io_base + DWC3_GCTL);
	reg |= DWC3_GCTL_CORESOFTRESET;
	__raw_writel(reg, pdev->io_base + DWC3_GCTL);
	udelay(100);
}

static void dwc3_controllor_exit(usb_hal_monitor_t * pdev)
{
	u32 reg;
	
	/*USB3 PLL disable*/
	act_writel(act_readl(pdev->usbpll) & ~(0x1f),pdev->usbpll);
	
	/*PLL1 disable*/	
	reg = __raw_readl(pdev->io_base + DWC3_CMU_DEBUG_LDO);
	reg &= ~CMU_BIAS_EN;
	__raw_writel(reg, pdev->io_base + DWC3_CMU_DEBUG_LDO);

	/*PLL2 disable*/
	reg = __raw_readl(pdev->io_base + DWC3_CMU_PLL2_BISTDEBUG);
	reg &= ~(BIST_QINIT(0x3) | EYE_HEIGHT(0x4) | PLL2_LOCK |
			PLL2_RS(0x2) | PLL2_ICP(0x1) | CMU_SEL_PREDIV |
			CMU_DIVX2 | PLL2_DIV(0x17) |PLL2_POSTDIV(0x3) |
			PLL2_PU);	
	__raw_writel(reg, pdev->io_base + DWC3_CMU_PLL2_BISTDEBUG);

	/*USB2 LDO disable*/
	reg = act_readl(pdev->usbecs );
	reg &= ~((1 << USB3_P0_CTL_PLLLDOEN )|(2 << USB3_P0_CTL_LDOVREFSEL_SHIFT));
	act_writel(reg, pdev->usbecs );
	
	udelay(100);
}

/*dwc3_controllor_otg_cfg��������������3�����;��ҪĿ����Ϊ����������������otgģʽ;
�Է�ֹid pin��״̬������ģʽ�¼�ⲻ׼.���õ��������,resume����,��⵽usb�γ�,���
��u�̰γ�.*/
/*dwc3_controllor_exit�����Ὣusbpll�ص�,Ŀǰ�����з���,�������������.����������,
dwc3(usb)�������ܻ�δж��,����Ȼ���ܷ���usb��������,����ʱ�Ѿ��ص���pll,�ᵼ������.*/
void dwc3_controllor_mode_cfg(usb_hal_monitor_t *pdev)
{
  u32 value;
  /*��Ϊ0,��ʾusb3֮ǰ��Ƶ�ʴ�,��������;����߲���Ҫ��Ƶ��;�˳�ʱ�಻��Ҫ�ر�Ƶ��*/
  value = act_readl(pdev->usbpll) & 0x1f;
  if(value == 0)
    dwc3_controllor_init(pdev);
    
  dwc3_set_mode(pdev, DWC3_GCTL_PRTCAP_OTG); 
  
  if(value == 0)
    dwc3_controllor_exit(pdev);
}


int usb_hal_init_monitor_hw_ops(usb_hal_monitor_t * pdev, 
	umon_port_config_t * config, unsigned int base)
{
	int ret = 0;
	
	pdev->name = "usb controller";
	pdev->io_base = base;
	pdev->usbecs = USB3_P0_CTL;
	pdev->usbpll = CMU_USBPLL;
	pdev->devrst = CMU_DEVRST1;

	pdev->vbus_power_onoff = usb_monitor_vbus_power;
	pdev->get_dc5v_state = usb_get_dc5v_state;
	pdev->get_vbus_state = usb_get_vbus_state;
	pdev->get_linestates = usb_get_linestates;
	pdev->get_idpin_state = usb_get_idpin_state;
	pdev->set_dp_500k_15k = usb_set_dp_500k_15k;
	pdev->set_soft_id = usb_set_soft_id;
	pdev->set_soft_vbus = usb_set_soft_vbus;
	pdev->aotg_enable = usb_hal_aotg_enable;
	pdev->set_mode = usb_hal_set_mode;
	pdev->set_cmu_usbpll = usb_hal_set_cmu_usbpll;
	pdev->dp_up = usb_hal_dp_up;
	pdev->dp_down = usb_hal_dp_down;
	pdev->is_sof = usb_hal_is_sof;
	pdev->enable_irq = usb_hal_enable_irq;
	pdev->debug = usb_hal_debug;
	pdev->suspend_or_resume = usb_suspend_or_resume;
	pdev->dwc3_otg_mode_cfg = dwc3_controllor_mode_cfg;
	pdev->dwc3_otg_exit = dwc3_controllor_exit;
  pdev->dwc3_otg_init = dwc3_controllor_init;


	pdev->config = config;
	return ret;
}


