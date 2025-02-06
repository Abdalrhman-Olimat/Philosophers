/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <aeleimat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:37:22 by aeleimat          #+#    #+#             */
/*   Updated: 2025/02/06 05:12:32 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

Gets the current time in milliseconds

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
Improved version of sleep function

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}



num of ph  die eat sleep [optional] times to eat 
*/
/*
error code
malloc safe value on success NULL on failure
22 - malloc error

safe_thread_handel 0 on success
12 - pthread_create error
13 - pthread_join error
14 - pthread_detach error

dinner start 0 on success
1 - number of meals is 0
else error code from safe_thread_handel



*/
void	handle_error_code(int error)
{
	if (error == 22)
		write(2, "Malloc error\n", 13);
	else if (error == 12)
		write(2, "pthread_create error\n", 22);
	else if (error == 13)
		write(2, "pthread_join error\n", 20);
	else if (error == 14)
		write(2, "pthread_detach error\n", 22);
}
int	main(int ac, char **av)
{
	t_table	table;
	int error_code;

	if (!input_error(ac, av))
	{
		parse_input(&table, av);
		if ((error_code = data_init(&table)) != 0 )
		{
			handle_error_code(error_code);
			return (1);
		}
		if ((error_code = dinner_start(&table)) != 0 )
		{
			handle_error_code(error_code);
			return (1);
		}
		clean(&table);
	}
	return (0);
}
