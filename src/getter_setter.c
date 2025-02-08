/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:03:51 by aeleimat          #+#    #+#             */
/*   Updated: 2025/02/08 11:15:06 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	safe_mutex_handel(mutex, LOCK);
	*dest = value;
	safe_mutex_handel(mutex, UNLOCK);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	va;

	safe_mutex_handel(mutex, LOCK);
	va = *value;
	safe_mutex_handel(mutex, UNLOCK);
	return (va);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	va;

	safe_mutex_handel(mutex, LOCK);
	va = *value;
	safe_mutex_handel(mutex, UNLOCK);
	return (va);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	safe_mutex_handel(mutex, LOCK);
	*dest = value;
	safe_mutex_handel(mutex, UNLOCK);
}

bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}
