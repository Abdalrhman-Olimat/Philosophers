#include "../includes/philo.h"


void    clean(t_table *table)
{
    t_philo *philo;
    int i;

    i = 0;
    while (i < table->philo_nbr)
    {
        philo = table->philos + i;
        safe_mutex_handel(&philo->philo_mutex, DESTROY);
        i++;
    }
    safe_mutex_handel(&table->write_mutex, DESTROY);
    safe_mutex_handel(&table->table_mutex, DESTROY);
    safe_mutex_handel(&table->printf_xx, DESTROY);
    free(table->fork);
    free(table->philos);
}

long    gettime(t_time_code time_code)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    if (time_code == SECOUND)
        return (tv.tv_sec + (tv.tv_usec / 1e6));
    else if (time_code == MILLISECOUND)
        return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
    else if (time_code == MICROSECOUND)
        return ((tv.tv_sec * 1e6) + tv.tv_usec);
    return (0);
}

void precise_usleep(long usec, t_table *table)
{
    long start;
    long elapsed;
    long rem;

    start = gettime(MICROSECOUND);
    while (gettime(MICROSECOUND) - start < usec)
    {
        if (simulation_finished(table))
            break ;
        elapsed = gettime(MICROSECOUND) - start;
        rem = usec - elapsed;
        if (rem > 1e3)
            usleep(rem / 2);
        else
            while (gettime(MICROSECOUND) - start < usec)
                ;
    }
}
