/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:04:33 by aeleimat          #+#    #+#             */
/*   Updated: 2025/02/08 12:52:25 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
*
void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
    long elapsed;

    elapsed = gettime(MILLISECOUND) - philo->table->start_simulation;
    if (philo->full)
        return ;
    safe_mutex_handel(&philo->table->printf_xx, LOCK);
    safe_mutex_handel(&philo->table->write_mutex, LOCK);
    if(debug)
        write_status_debug(status, philo, elapsed);
    else
    {
    if((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
		&& !simulation_finished(philo->table))
        printf(BGBLACK BOLD MAGENTA"%-6ld %d has taken a fork\n" RESET, elapsed,
		philo->id);
    else if(EATING == status && !simulation_finished(philo->table))
        printf(BGBLACK BOLD YELLOW"%-6ld %d is eating\n" RESET, elapsed,
		philo->id);
    else if(SLEEPING == status && !simulation_finished(philo->table))
        printf(BGBLACK BOLD BLUE"%-6ld %d is sleeping\n"RESET, elapsed,
		philo->id);
    else if(THINKING == status && !simulation_finished(philo->table))
        printf(BGBLACK BOLD GREEN"%-6ld %d is thinking\n"RESET, elapsed,
		philo->id);
    else if(DEAD == status && !simulation_finished(philo->table))
        printf(BGBLACK BOLD RED"%-6ld %d died\n" RESET, elapsed, philo->id);
    }
safe_mutex_handel(&philo->table->printf_xx, UNLOCK);
safe_mutex_handel(&philo->table->write_mutex, UNLOCK);
}
*/

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	(void)debug;
	elapsed = gettime(MILLISECOUND) - philo->table->start_simulation;
	if (philo->full)
		return ;
	safe_mutex_handel(&philo->table->write_mutex, LOCK);
	if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
		&& !simulation_finished(philo->table))
		printf(BGBLACK BOLD MAGENTA "%-6ld %d has taken a fork\n" RESET,
			elapsed, philo->id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf(BGBLACK BOLD YELLOW "%-6ld %d is eating\n" RESET, elapsed,
			philo->id);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf(BGBLACK BOLD BLUE "%-6ld %d is sleeping\n" RESET, elapsed,
			philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf(BGBLACK BOLD GREEN "%-6ld %d is thinking\n" RESET, elapsed,
			philo->id);
	else if (DEAD == status && !simulation_finished(philo->table))
		printf(BGBLACK BOLD RED "%-6ld %d died\n" RESET, elapsed, philo->id);
	safe_mutex_handel(&philo->table->write_mutex, UNLOCK);
}
