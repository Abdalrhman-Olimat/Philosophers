#include "../includes/philo.h"

void    *safe_malloc(size_t byte)
{
    void    *ret;

    ret = malloc(byte);
    if (ret == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    return (ret);
}
void    safe_mutex_handel(pthread_mutex_t *mutex, t_opcode opcode)
{
    if(opcode == LOCK)
        pthread_mutex_lock(mutex);
    else if(opcode == UNLOCK)
        pthread_mutex_unlock(mutex);
    else if(opcode == DESTROY)
        pthread_mutex_destroy(mutex);
    else if(opcode == INIT)
        pthread_mutex_init(mutex, NULL);
    else
        {
        printf("Error: invalid opcode\n");
        exit(1);
        }
}
void    safe_thread_handel(pthread_t *thread, void *(*foo)(void *),void *data,t_opcode opcode)
{
    if(opcode == CREATE)
        pthread_create(thread, NULL, foo, data);
    else if(opcode == JOIN)
        pthread_join(*thread, NULL);
    else if(opcode == DETACH)
        pthread_detach(*thread);
    else
        {
        printf("Error: invalid opcode\n");
        exit(1);
        }
}
