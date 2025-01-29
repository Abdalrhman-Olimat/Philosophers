#include "../includes/test.h"

/*
void my_exit(int status) {
    __asm__ volatile (
        "mov $1, %%eax\n\t"  // Syscall 1 for exit on x86
        "mov %0, %%ebx\n\t"  // Status in ebx
        "int $0x80"
        :
        : "r" (status)
        : "%eax", "%ebx"
    );
}
*/
void input_error()
{
	printf("Error: invalid input\n");
	
}
int main (int ac, char **av)
{
	if (ac = 5)
	{
		
	}
	input_error();
	return 0;
}