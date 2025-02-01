#include "../includes/philo.h"

static int	ft_isdigit(int a)
{
	if ((a >= '0' && a <= '9') || a == '+')
		return (1);
	return (0);
}

int input_error(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	if(ac != 5 && ac != 6)
	{
		printf("Error: invalid input\n");
		return 1;
	}
	while(i < ac)
	{
		j = 0;
		while(av[i][j])
		{
			if(!(ft_isdigit(av[i][j])))
			{
				printf("Error: invalid input not nuumber\n");
				return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}
