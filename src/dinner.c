/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:03:45 by aeleimat          #+#    #+#             */
/*   Updated: 2025/02/08 10:24:15 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

 void think(t_philo *philo, bool pre_simulation)
{
   long	time_to_eat;
	long	time_to_sleep;
	long	time_to_think;

	if (!pre_simulation)
		write_status(THINKING, philo, DEBUG_MODE);
  	if (philo->table->philo_nbr % 2 == 0)
		return ;
	time_to_eat = philo->table->time_to_eat;
	time_to_sleep = philo->table->time_to_sleep;
	time_to_think = (time_to_eat * 2) - time_to_sleep;
	if (time_to_think < 0)
		time_to_think = 0;
	precise_usleep(time_to_think * 0.42, philo->table);
}

void    *long_philo(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_all_threads(philo->table);
    set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOUND));
    increase_long(&philo->table->table_mutex, &philo->table->threads_running_nbr);
    write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
    while(!simulation_finished(philo->table))
        usleep(200);
    return (NULL);
}
static void eat(t_philo *philo)
{
    safe_mutex_handel(&philo->first_fork->fork, LOCK);
    write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
    safe_mutex_handel(&philo->second_fork->fork, LOCK);
    write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
    set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOUND));
    philo->meals_counter++;
    write_status(EATING, philo, DEBUG_MODE);
    precise_usleep(philo->table->time_to_eat, philo->table);
    if (philo->table->nbr_limit_meals > 0 && philo->meals_counter == philo->table->nbr_limit_meals)
        set_bool(&philo->philo_mutex, &philo->full, true);
    safe_mutex_handel(&philo->first_fork->fork, UNLOCK);
    safe_mutex_handel(&philo->second_fork->fork, UNLOCK);
} 



void *dinner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_all_threads(philo->table);
    set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOUND));
    increase_long(&philo->table->table_mutex, &philo->table->threads_running_nbr);
    unsynchronize_philos(philo);
    while(!simulation_finished(philo->table))
    {
        if(get_bool(&philo->philo_mutex, &philo->full))
            break;
        eat(philo);
        write_status(SLEEPING, philo, DEBUG_MODE);
        precise_usleep(philo->table->time_to_sleep, philo->table);
        think(philo, false);
    }
        return NULL;
}


int    dinner_start(t_table *table)
{
    int i;
    int error;

    i = -1;
    if (table->nbr_limit_meals == 0)
        return 1;
    else if (table->philo_nbr == 1)
    {
        if ((error = safe_thread_handel(&table->philos[0].thread_id, long_philo, &table->philos[0], CREATE)) != 0)
            return error;
    }
    else
    {
        while (++i < table->philo_nbr)
        {
            if ((error = safe_thread_handel(&table->philos[i].thread_id, dinner_simulation, &table->philos[i], CREATE)) != 0)
                return error;
        }
    }
    if ((error = safe_thread_handel(&table->monitor, monitor_dinner, table, CREATE)) != 0)
        return error;
    table->start_simulation = gettime(MILLISECOUND);
    set_bool(&table->table_mutex, &table->all_thread_ready, true);
    i = -1;
    while (++i < table->philo_nbr)
    {
        if ((error = safe_thread_handel(&table->philos[i].thread_id, NULL, NULL, JOIN)) != 0)
            return error;
    }
    set_bool(&table->table_mutex, &table->end_simulation, true);
    if ((error = safe_thread_handel(&table->monitor, NULL, NULL, JOIN)) != 0)
        return error;
    return 0;
}

