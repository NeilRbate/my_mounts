#include <linux/init.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/path.h>
#include <linux/mount.h>
#include <linux/namei.h>
#include <linux/list.h>
#include <linux/dcache.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Julien Barbate <julienb@rbate.fr>");
MODULE_DESCRIPTION("List all mount point on system");

ssize_t	mymounts_read(struct file *f, char __user *buff,
			size_t len, loff_t *offset);

static struct	proc_ops	mymounts_pops = {
	.proc_read	= mymounts_read,
};

ssize_t	mymounts_read(struct file *f, char __user *buff,
			size_t len, loff_t *offset)
{
	struct path		path;
	struct vfsmount		*mount;
	struct super_block	*sb;
	struct dentry		*dtry;

	if (kern_path("/", LOOKUP_FOLLOW, &path))
		return -ENOMEM;

	mount = path.mnt;
	dtry = path.dentry;

	sb = mount->mnt_sb;

	struct hlist_node	*node;
	struct dentry		*child;

	hlist_for_each(node, &dtry->d_children) {

		child = hlist_entry(node, struct dentry, d_sib);

		if (child->d_flags & DCACHE_MOUNTED) {

			if (strcmp(child->d_iname, "root") == 0)
				pr_info("%s      /", child->d_iname);
			else {
				if (strlen(child->d_iname) == 3)
					pr_info("%s       /%s", child->d_iname, child->d_iname);
				else
					pr_info("%s      /%s", child->d_iname, child->d_iname);
			}
		}
	}

	return 0;
}

static int	__init mymounts_init(void)
{
	proc_create("my_mounts", O_RDONLY, NULL, &mymounts_pops);
	return 0;
}

static void	__exit mymounts_exit(void)
{
	remove_proc_entry("my_mounts", NULL);
}
module_init(mymounts_init);
module_exit(mymounts_exit);
