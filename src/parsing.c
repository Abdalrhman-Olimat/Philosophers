#include "../includes/philo.h"
//handel max_int
static long	ft_atol(const char *str)
{
	long	i;
	long	result;
	long	signal;

	signal = 1;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * signal);
}
//handel < 60ms
void    parse_input(t_table *table, char **av)
{
    table->philo_nbr = ft_atol(av[1]);
    table->time_to_die = ft_atol(av[2]) * 1000;
    table->time_to_eat = ft_atol(av[3]) * 1000;
    table->time_to_sleep = ft_atol(av[4]) * 1000;
    if (av[5])
        table->nbr_limit_meals = ft_atol(av[5]);
    else
        table->nbr_limit_meals = -1;


}
