# include "../includes/philo.h"

static void write_status_debug(t_philo_status status, t_philo *philo, long elapsed)
{
    if(TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
        printf("%-6ld %d has taken the 1 fork\n", elapsed, philo->id);
    else if(TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
        printf("%-6ld %d has taken the 2 fork\n", elapsed, philo->id);
    else if(EATING == status && !simulation_finished(philo->table))
        printf("%-6ld %d is eating\t\t[%d]", elapsed, philo->id,philo->meals_counter);
    else if(SLEEPING == status && !simulation_finished(philo->table))
        printf("%-6ld %d is sleeping\n", elapsed, philo->id);
    else if(THINKING == status && !simulation_finished(philo->table))
        printf("%-6ld %d is thinking\n", elapsed, philo->id);
    else if(DEAD == status && !simulation_finished(philo->table))
        printf("%-6ld %d died\n", elapsed, philo->id);
}



void write_status(t_philo_status status, t_philo *philo, bool debug)
{
    long elapsed;

    elapsed = gettime(MILLISECOUND) - philo->table->start_simulation;
    if (philo->full)
        return;
    safe_mutex_handel(&philo->table->printf_xx, LOCK);
    safe_mutex_handel(&philo->table->write_mutex, LOCK);
    if(debug)
        write_status_debug(status, philo, elapsed);
    else
    {
    if((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status) && !simulation_finished(philo->table))
        printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
    else if(EATING == status && !simulation_finished(philo->table))
        printf("%-6ld %d is eating\n", elapsed, philo->id);
    else if(SLEEPING == status && !simulation_finished(philo->table))
        printf("%-6ld %d is sleeping\n", elapsed, philo->id);
    else if(THINKING == status && !simulation_finished(philo->table))
        printf("%-6ld %d is thinking\n", elapsed, philo->id);
    else if(DEAD == status && !simulation_finished(philo->table))
        printf("%-6ld %d died\n", elapsed, philo->id);
    }
safe_mutex_handel(&philo->table->printf_xx, UNLOCK);
safe_mutex_handel(&philo->table->write_mutex, UNLOCK);
}
