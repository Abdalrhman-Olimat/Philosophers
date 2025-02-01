#include "../includes/philo.h"


void *dinner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    

}


void    dinner_start(t_table *table)
{
    int i;

    i = -1;
    if(table->nbr_limit_meals == 0)
        return;
    else if(table->nbr_limit_meals == 1)
        ;
    else
    {
        while(++i < table->philo_nbr)
            safe_thread_handel(&table->philos[i].thread_id, dinner_simulation,
                &table->philos[i], CREATE);
        
    }
    set_bool(&table->table_mutex, &table->all_thread_ready, true);
}
