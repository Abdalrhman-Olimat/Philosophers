#include "../includes/philo.h"

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
}