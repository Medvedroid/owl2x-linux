
#ifndef __REMOTE_IO_H__
#define __REMOTE_IO_H__

#ifdef MAX_PATH
#undef MAX_PATH
#endif
#define MAX_PATH                800	//1024
#define MAX_ROOT_PATH           256
#define REMOTE_FS_PC_MAX_PATH   MAX_PATH
#define REMOTE_FS_MAX_PATH      MAX_PATH

struct remote_io;

struct remote_io_ops {
    int (*open)(struct remote_io *io, const char *pathname, int flags, int mode);
    int (*close)(struct remote_io *io, int fd);
    ssize_t (*read)(struct remote_io *io, int fd, char __user *buf, size_t count);
    ssize_t (*write)(struct remote_io *io, int fd, const char __user *buf, size_t count);
    loff_t (*lseek)(struct remote_io *io, int fd, loff_t offset, int flag);
    int (*system)(struct remote_io *io, const char *command);
    int (*call_internal)(struct remote_io *io, const char *command);
    int (*send_usdk_info)(struct remote_io *io, const unsigned char *ptr, int length);
    long long (*tell)(struct remote_io *io, int fd);
    int (*rename)(struct remote_io *io, const char *oldpath, const char *newpath);
    int  (*remove)(struct remote_io *io, const char *pathname);
    int (*readdir)(struct remote_io *io, int fd, loff_t pos, void __user * ent , int len);
    int (*seekdir)(struct remote_io *io, int fd, loff_t offset);
    int (*rewinddir)(struct remote_io *io, int fd);
    int (*mkdir)(struct remote_io *io, const char *path, mode_t mode);
    int (*rmdir)(struct remote_io *io, const char *path);
    int (*fstat) (struct remote_io *io, int fd, void __user *buf );
    int (*stat) (struct remote_io *io, const char __user *path, void __user *buf);
    int (*statfs) (struct remote_io *io, const char __user *pathname, void __user * buf );
    int (*lastdir)(struct remote_io *io, int fd);
    int (*prevdir)(struct remote_io *io, int fd, loff_t pos, void __user *buf, int len);
    int (*reset2parentdir)(struct remote_io *io, int fd);
    int (*truncate)(struct remote_io *io, const char *pathname, long long len);
    int (*ftruncate)(struct remote_io *io, int fd, long long len);
       
};

struct remote_io {
    spinlock_t io_lock;
    char pc_root_path[MAX_ROOT_PATH];
    char pc_root_path_win_type[MAX_ROOT_PATH];
    u8   load_flag;
    u8   path_type;
    int  path_ready : 1;
    int  load_ready : 1;
    struct completion *complete;
    wait_queue_head_t remotefs_wait_queue;
    struct remote_io_ops ops;
    void  *buf_for_user;
    int remotefs_call_handle : 1;
    int remote_io_exit : 1;
    loff_t ret;
	struct module *owner;   
    unsigned long		private;
};

#define REMOTEFS_ENTRY_NAME_MAX     256

typedef struct remotefs_dirent
{
    /*! �ļ����к�*/
    unsigned int d_ino;   
    /*! Ŀ¼ͷ�����ļ�Ŀ¼���ƫ����*/
    unsigned int  d_off; 
    /*! �ļ��޸�ʱ�� */
    unsigned int d_mtime;    
    /*! �ü�¼���ܳ���,������¼ͷ���ļ���.32b����*/
    unsigned short int d_reclen;    
    /*! �ļ��������ԣ�λ�������£�
     * \n ATTR_READONLY��λ:ֻ���ļ�
     * \n ATTR_HIDDEN��λ:�����ļ�
     * \n ATTR_SYSTEM��λ��ϵͳ�ļ�
     * \n ATTR_VOLUME��λ:����ļ�
     * \n ATTR_DIRECTORY��λ:Ŀ¼�ļ�
     * \n ATTR_ARCHIVE��λ:�浵�ļ� */
    unsigned char  d_type;    
    /*! �ļ�����Сд��ʾλ*/
    unsigned char  d_lcase;    
    /*! �ļ���,�ɱ䳤.����Ϊ = ��¼����(d_reclen) - 
        offsetof(struct dirent, d_name)
    */
    char  d_name[REMOTEFS_ENTRY_NAME_MAX];
}remotefs_dirent_t;

#if 0
struct remotefs_stat {
   dev_t     st_dev;     /* ID of device containing file */
   ino_t     st_ino;     /* inode number */
   mode_t    st_mode;    /* protection */
   nlink_t   st_nlink;   /* number of hard links */
   uid_t     st_uid;     /* user ID of owner */
   gid_t     st_gid;     /* group ID of owner */
   dev_t     st_rdev;    /* device ID (if special file) */
   off_t     st_size;    /* total size, in bytes */
   long      st_blksize; /* blocksize for file system I/O */
   long      st_blocks;  /* number of 512B blocks allocated */
   time_t    st_atime;   /* time of last access */
   time_t    st_mtime;   /* time of last modification */
   time_t    st_ctime;   /* time of last status change */
};
#endif

struct remotefs_stat {
    unsigned int    st_dev; /*! �ļ����ڵ��豸�ı��*/
    unsigned int     st_ino; /*! �ļ����к�*/
    unsigned int     st_mode; /*! �ļ������ͺʹ洢Ȩ��*/
    unsigned int     st_nlink; /*! ���Ӹ��ļ���Ӳ������Ŀ*/
    unsigned int     st_uid; /*! �ļ������ߵ��û�ʶ����*/
    unsigned int     st_gid; /*! �ļ������ߵ���ʶ����*/
    unsigned int     st_rdev; /*! ������豸Ϊ�豸��*/
    unsigned int     st_size; /*! �ļ���С����λbyte*/
    unsigned long st_blksize; /*! �ļ�ϵͳ��I/O��������С*/
    unsigned long st_blocks; /*! �ļ�ռ���ļ�����ĸ���������СΪ512byte*/
    time_t   st_atime; /*! �ļ����һ�α���ȡ��ִ�е�ʱ��*/
    time_t   st_mtime; /*! �ļ����һ�����ݱ����ĵ�ʱ��*/
    time_t   st_ctime; /*! �ļ����һ���޸����Ե�ʱ��*/
};

typedef struct remotefs_stat remotefs_stat_t;

/*!

 * \brief  

 *      �ļ�ϵͳ״̬�ṹ����

 */

typedef struct remotefs_statfs
{
         /*! �ļ�ϵͳ����*/
         unsigned int    f_type;
         /*! ���С��ش�С*/
         unsigned int    f_bsize;
         /*! �����ļ�ϵͳ���С*/
         unsigned int    f_frsize;
         /*! �ܹ����ж��ٸ����ݿ飬���ж��ٸ���*/
         unsigned int    f_blocks;
         /*! �ܹ�û��ʹ�õ����ݿ飬��û��ʹ�õĴ�*/
         unsigned int    f_bfree;
         /*! ���п��������ͨ�ļ��ĸ���*/
         unsigned int    f_bavail;
         /*! �ļ��������*/
         unsigned int    f_files;
         /*! �����ļ��������*/
         unsigned int    f_ffree;
         /*! ��ͨ�ļ�������ʹ�õĿ��ļ�*/
         unsigned int    f_favail;
         /*! �ļ�ϵͳid*/
         unsigned int    f_fsid;
         /*! �ļ�ϵͳflag*/
         unsigned int    f_flag;
         /*! �ļ�ϵͳ������ļ�����󳤶�*/
         unsigned int    f_namemax;
}remotefs_statfs_t;


struct entry_inode_num {
    struct list_head list;
    int num;  
    char name[REMOTEFS_ENTRY_NAME_MAX];
};


struct remotefs_inode_info {
    struct list_head    file_list;
    struct list_head    entry_list;
    ino_t     st_ino;     /* inode number */
    mode_t    st_mode;    /* protection */
    nlink_t   st_nlink;   /* number of hard links */
    uid_t     st_uid;     /* user ID of owner */
    gid_t     st_gid;     /* group ID of owner */
    off_t     st_size;    /* total size, in bytes */
    u32        st_blksize; /* blocksize for file system I/O */
    u32         st_blocks;  /* number of 512B blocks allocated */
    time_t    st_atime;   /* time of last access */
    time_t    st_mtime;   /* time of last modification */
    time_t    st_ctime; 
    struct inode       vfs_inode;   
};

struct remotefs_sb_info {
	unsigned int rsize;
	unsigned int wsize;
	uid_t	mnt_uid;
	gid_t	mnt_gid;
	mode_t	mnt_file_mode;
	mode_t	mnt_dir_mode;
	struct super_block *sb;
};

#define REMOTEFS_ROOT_I     2

static inline struct remotefs_sb_info *
REMOTEFS_SB(struct super_block *sb)
{
	return sb->s_fs_info;
}

static inline struct remotefs_inode_info *
REMOTEFS_I(struct inode *inode)
{
	return container_of(inode, struct remotefs_inode_info, vfs_inode);
}


#endif

