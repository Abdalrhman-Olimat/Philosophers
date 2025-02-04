#include "../includes/philo.h"


// void my_exit(int status) {
// 	__asm__ volatile (
// 		"mov $1, %%eax\n\t"  // Syscall 1 for exit on x86
// 		"mov %0, %%ebx\n\t"  // Status in ebx
// 		"int $0x80"
// 		:
// 		: "r" (status)
// 		: "%eax", "%ebx"
// 	);
// }

/*
// Gets the current time in milliseconds

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
// Improved version of sleep function
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
*/



// num of ph  die eat sleep
int main (int ac, char **av)
{
	t_table	table;

	if(!input_error(ac,av))
	{
		parse_input(&table,av);
		data_init(&table);//57
		dinner_start(&table);
		clean(&table);
	}
	else
	{
		write(2, "Invalid input\n", 14);
		return (1);
	}
	return (0);
}