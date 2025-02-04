#include "../includes/philo.h"

/*
spinlock
*/
void wait_all_threads(t_table *table)
{
    while(!get_bool(&table->table_mutex, &table->all_thread_ready))
    ;
}

bool    all_thread_running(pthread_mutex_t *mutex, long *threads,
        long philo_nbr)
{
    bool ret;

    ret = false;
    safe_mutex_handel(mutex, LOCK);
    if (*threads == philo_nbr)
        ret = true;
    safe_mutex_handel(mutex, UNLOCK);
    return (ret);

}
void increase_long(pthread_mutex_t *mutex, long *value)
{
    safe_mutex_handel(mutex, LOCK);
    *value += 1;
    safe_mutex_handel(mutex, UNLOCK);
}