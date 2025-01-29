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
int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int input_error(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	if(ac != 5 )
	{
		printf("Error: invalid input\n");
		return 1;
	}
	while(i < ac)
	{
		j = 0;
		while(av[i][j])
		{
			if(!(ft_isdigit(av[i][j])))
			{
				printf("Error: invalid input not nuumber\n");
				return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}

int main (int ac, char **av)
{
	if (!input_error(ac,av))
	{
		
	}
	return 0;
}