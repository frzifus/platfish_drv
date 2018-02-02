#include <linux/init.h>
#include <linux/module.h>

#include <linux/fs.h>


int platfish_open(struct inode *pinode, struct file *pfile)
{
  printk(KERN_ALERT "Someone looks at platfish\n");
  return 0;
}

ssize_t platfish_read(struct file *pfile, char __user *buffer, size_t length,
                  loff_t *offset)
{
  printk(KERN_ALERT "Somebody reads platfish\n");
  return 0;
}

ssize_t platfish_write(struct file *pfile, const char __user *buffer,
                       size_t length, loff_t *offset)
{
  printk(KERN_ALERT "Somebody sends platfish a letter\n");
  return length;
}

int platfish_close(struct inode *pinode, struct file *pfile)
{
  printk(KERN_ALERT "Someone's had enough of platfish\n");
  return 0;
}

/* To hold the file operations performed on this device */
struct file_operations platfish_file_operations = {
  .owner   = THIS_MODULE,
  .open    = platfish_open,
  .read    = platfish_read,
  .write   = platfish_write,
  .release = platfish_close,
};

int platfish_module_init(void)
{
  printk(KERN_ALERT "Platfish joined the kernel\n");
  register_chrdev(240, "platfish_drv", &platfish_file_operations);
  return 0;
}

void platfish_module_exit(void)
{
  printk(KERN_ALERT "platfish left the kernel\n");
  unregister_chrdev(240, "platfish_drv");
}

module_init(platfish_module_init);
module_exit(platfish_module_exit);
