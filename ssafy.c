#include <linux/module.h>
#include <linux/printk.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define NOD_NAME "ssafyFile"

MODULE_LICENSE("GPL");

static int NOD_MAJOR = 100;
// static struct class *cls;
// static dev_t dev;

struct Node{
    char n;
    char buf[30];
};


static int ssafy_open(struct inode *inode, struct file *filp){
        pr_info("Open ssafyFile\n");
        return 0;
}

static int ssafy_release(struct inode *inode, struct file *filp){
        pr_info("Close ssafyFile\n");
        return 0;
}

static ssize_t ssafy_ioctl(struct file *filp, unsigned int cmd, unsigned long arg){
    pr_alert("command number: %d\n", cmd);

    struct Node readData;
    struct Node writeData = {21, "I'm Melody"};
    int ret;
    switch(cmd){
        case _IO(0,3):
            ret = copy_to_user((void*)arg, &writeData, sizeof(struct Node));
            pr_info("Send to User!\n");
            break;
        case _IO(0,4):
            ret = copy_from_user(&readData, (void*)arg, sizeof(struct Node));
            pr_info("from User : %c %s\n", readData.n, readData.buf);
            break;
    }


    return 0;
}
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = ssafy_open,
    .release = ssafy_release,
    .unlocked_ioctl = ssafy_ioctl,
};


static int __init ssafy_init(void){
    NOD_MAJOR = register_chrdev(NOD_MAJOR, NOD_NAME, &fops);
    if( NOD_MAJOR < 0 ){
        pr_alert("Register File\n");
        return NOD_MAJOR;
    }

    pr_info("Insmod Module\n");

//    dev = MKDEV(NOD_MAJOR, 0);
//    cls = class_create(NOD_NAME);
//    device_create(cls, NULL, dev, NULL, NOD_NAME);

        return 0;
}
static void __exit ssafy_exit(void){
//    device_destroy(cls, MKDEV(NOD_MAJOR, 0));
//    class_destroy(cls);

    unregister_chrdev(NOD_MAJOR, NOD_NAME);

}
module_init(ssafy_init);
module_exit(ssafy_exit);
