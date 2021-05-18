//通过class_create()、class_destroy()去注册和注销/sys/class/my_char_dev

#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>

struct class *mem_class;

static int __init class_create_init(void)
{
	// class_create动态创建设备的逻辑类，并完成部分字段的初始化，然后将其添加到内核中。创建的逻辑类位于/sys/class/。
    // 参数：
    //        owner, 拥有者。一般赋值为THIS_MODULE。
    //        name, 创建的逻辑类的名称。
	mem_class=class_create(THIS_MODULE,"my_test_dev");
	if(mem_class == NULL)
	{
		printk("Create failed!\n");
		return -1;
	}
	printk("Create Success!\n");
	return 0;
}

static void __exit class_destroy_exit(void)
{
	if(mem_class != NULL)
	{
		class_destroy(mem_class);
		mem_class=NULL;
		printk("Destroy Success!\n");
	}
	return 0;
}

module_init(class_create_init);
module_exit(class_destroy_exit);
MODULE_LICENSE("GPL");
