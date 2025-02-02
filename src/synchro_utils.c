#include "../includes/philo.h"

/*
spinlock
*/
void wait_all_threads(t_table *table)
{
    while(!get_bool(&table->table_mutex, &table->all_thread_ready))
    ;
}