/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:04:15 by aeleimat          #+#    #+#             */
/*   Updated: 2025/02/08 11:09:10 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	philo_died(t_philo *philo)
{
	long	passed;
	long	time_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	passed = gettime(MILLISECOUND) - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	time_to_die = philo->table->time_to_die / 1000;
	if (passed > time_to_die)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	int		i;
	t_table	*table;

	table = (t_table *)data;
	while (!all_thread_running(&table->table_mutex, &table->threads_running_nbr,
			table->philo_nbr))
		;
	while (!simulation_finished(table))
	{
		i = -1;
		while (++i < table->philo_nbr)
		{
			if (philo_died(&table->philos[i]))
			{
				write_status(DEAD, &table->philos[i], DEBUG_MODE);
				set_bool(&table->table_mutex, &table->end_simulation, true);
				return (NULL);
			}
		}
	}
	return (NULL);
}
