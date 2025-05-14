/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <aeleimat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:03:45 by aeleimat          #+#    #+#             */
/*   Updated: 2025/05/14 20:33:18 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	int	create_single_philo_thread(t_table *table)
{
	return (safe_thread_handel(&table->philos[0].thread_id,
			long_philo, &table->philos[0], CREATE));
}

static	int	create_philo_threads(t_table *table)
{
	int	i;
	int	error;

	i = -1;
	while (++i < table->philo_nbr)
	{
		error = safe_thread_handel(&table->philos[i].thread_id,
				dinner_simulation, &table->philos[i], CREATE);
		if (error != 0)
			return (error);
	}
	return (0);
}

static	int	create_monitor_and_start(t_table *table)
{
	int	error;

	error = safe_thread_handel(&table->monitor, monitor_dinner, table, CREATE);
	if (error != 0)
		return (error);
	table->start_simulation = gettime(MILLISECOUND);
	set_bool(&table->table_mutex, &table->all_thread_ready, true);
	return (0);
}

static	int	join_threads_and_cleanup(t_table *table)
{
	int	i;
	int	error;

	i = -1;
	while (++i < table->philo_nbr)
	{
		error = safe_thread_handel(&table->philos[i].thread_id,
				NULL, NULL, JOIN);
		if (error != 0)
			return (error);
	}
	set_bool(&table->table_mutex, &table->end_simulation, true);
	return (safe_thread_handel(&table->monitor, NULL, NULL, JOIN));
}

int	dinner_start(t_table *table)
{
	int	error;

	if (table->nbr_limit_meals == 0)
		return (1);
	if (table->philo_nbr == 1)
		error = create_single_philo_thread(table);
	else
		error = create_philo_threads(table);
	if (error != 0)
		return (error);
	error = create_monitor_and_start(table);
	if (error != 0)
		return (error);
	return (join_threads_and_cleanup(table));
}
