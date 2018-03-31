#define UNIT_TEST_ENABLED 0

#if (UNIT_TEST_ENABLED==0)
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Robert W. Oliver II");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");
#endif



unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}



#if (UNIT_TEST_ENABLED==0)
static int __init lkm_example_init(void) {
 printk(KERN_INFO "Hello, World!\n");
 printk(KERN_INFO "%d\n",Factorial(1));
 return 0;
}

static void __exit lkm_example_exit(void) {
 printk(KERN_INFO "Goodbye, World!\n");
}

module_init(lkm_example_init);
module_exit(lkm_example_exit);
#endif



#if UNIT_TEST_ENABLED

#include <assert.h>

int main(void)
{
	printf("Unit test started");
	assert(Factorial(1) == 1);
	assert(Factorial(2) == 2);
	assert(Factorial(3) == 6);
	printf("Unit test ended");
}

#endif

