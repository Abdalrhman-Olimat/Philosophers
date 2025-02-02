#include "../includes/philo.h"

static void assign_forks(t_philo *phio, t_fork *forks, int i)
{
    int philo_nbr;

    philo_nbr = phio->table->philo_nbr;
    if (phio->id % 2 == 0)
    {
        phio->first_fork = &forks[i];
        phio->second_fork = &forks[(i + 1) % philo_nbr];
    }
    else
    {
        phio->first_fork = &forks[(i + 1) % philo_nbr];
        phio->second_fork = &forks[i];
    }
}

static void philo_init(t_table *table)
{
    int i;
    t_philo *philo;
    i = -1;
    while(++i < table->philo_nbr)
    {
        philo = table->philos + i;
        philo->id = i + 1;
        philo->full = false;
        philo->meals_counter = 0;
        philo->table = table;
        assign_forks(philo, table->fork, i);
    }
}

void    data_init(t_table *table)
{
    int i;

    i = -1;
    table->end_simulation = false;
    table->all_thread_ready = false;
    table->philos = safe_malloc(sizeof(t_philo) * table->philo_nbr);
    safe_mutex_handel(&table->table_mutex, INIT);
    table->fork = safe_malloc(sizeof(t_fork) * table->philo_nbr);
    while(++i < table->philo_nbr)
    {
        safe_mutex_handel(&table->fork[i].fork, INIT);
        table->fork[i].fork_id = i;
    }
    philo_init(table);
}

