/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <aeleimat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:04:22 by aeleimat          #+#    #+#             */
/*   Updated: 2025/02/06 05:04:23 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	*safe_malloc(size_t byte)
{
	void    *ret;

	ret = malloc(byte);
	return (ret);
}

void    safe_mutex_handel(pthread_mutex_t *mutex, t_opcode opcode)
{
	if(opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if(opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if(opcode == DESTROY)
		pthread_mutex_destroy(mutex);
	else if(opcode == INIT)
		pthread_mutex_init(mutex, NULL);
}

int    safe_thread_handel(pthread_t *thread, void *(*foo)(void *),void *data,t_opcode opcode)
{
	if(opcode == CREATE)
	{
		if(pthread_create(thread, NULL, foo, data) != 0)
			return 12;
	}
	else if(opcode == JOIN)
	{
		if(pthread_join(*thread, NULL) != 0)
			return 13;
	}
	else if(opcode == DETACH)
	{
		if(pthread_detach(*thread) != 0)
			return 14;
	}
	return 0;
}
