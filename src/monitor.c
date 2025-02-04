#include "../includes/philo.h"

// void monitor_dinner(void *data)
// {
//     int i;
//     t_table *table;

//     table = (t_table *)data;
//     while (!all_thread_running(&table->table_mutex, &table->threads_running_nbr, table->philo_nbr))
//         ;
//     while (!simulation_finished(table))
//     {
//         i = -1;
//         while (++i < table->philo_nbr)
//         {
//             if (gettime(MILLISECOUND) - table->philos[i].last_meal_time > table->time_to_die)
//             {
//                 write_status(DEAD, &table->philos[i], DEBUG_MODE);
//                 set_bool(&table->table_mutex, &table->end_simulation, true);
//                 return;
//             }
//         }
//     }
//     return(NULL);
// }


static bool philo_died(t_philo *philo)
{
    long elapsed;
    long t_to_die;

    if(get_bool(&philo->table->table_mutex, &philo->full))
        return (false);
    elapsed = gettime(MILLISECOUND) - get_long(&philo->philo_mutex, &philo->last_meal_time);
    t_to_die = philo->table->time_to_die / 1000; // Convert to milliseconds//1:45:12
    if (elapsed > t_to_die)
        return (true);
    return (false);
}

void *monitor_dinner(void *data)
{
    int i;
    t_table *table;

    table = (t_table *)data;
    while (!all_thread_running(&table->table_mutex, &table->threads_running_nbr, table->philo_nbr))
        ;
    while (!simulation_finished(table))
    {
        i = -1;
        while (++i < table->philo_nbr && !simulation_finished(table))
        {
           if (philo_died(table->philos + i))
            {
                write_status(DEAD, table->philos + i, DEBUG_MODE);
                set_bool(&table->table_mutex, &table->end_simulation, true);
            }
        }
    }
    return NULL;
}