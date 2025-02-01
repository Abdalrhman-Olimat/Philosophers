# include "../includes/philo.h"

void set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
    safe_mutex_handel(mutex, LOCK);
    *dest = value;
    safe_mutex_handel(mutex, UNLOCK);
}

bool get_bool(pthread_mutex_t *mutex, bool *value)
{
    bool value;

    safe_mutex_handel(mutex, LOCK);
    value = *value;
    safe_mutex_handel(mutex, UNLOCK);
    return (value);
}

long get_long(pthread_mutex_t *mutex, long *value)
{
    long value;

    safe_mutex_handel(mutex, LOCK);
    value = *value;
    safe_mutex_handel(mutex, UNLOCK);
    return (value);
}

void set_long(pthread_mutex_t *mutex, long *dest, long value)
{
    safe_mutex_handel(mutex, LOCK);
    *dest = value;
    safe_mutex_handel(mutex, UNLOCK);
}

void simulation_finished(t_table *table)
{
    return(get_bool(&table->table_mutex, &table->end_simulation));
}
