#ifndef philo_H
# define philo_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>


typedef	enum	e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_opcode;

typedef enum e_time_code
{
	SECOUND,
	MILLISECOUND,
	MICROSECOUND,
}	t_time_code;

typedef struct s_table t_table; // Forward declare t_table using typedef
typedef struct s_fork
{
	pthread_mutex_t fork;
	int				fork_id;
}		t_fork;


typedef struct s_philo {
    int 		id;
    pthread_t	thread_id;
    int			meals_counter;	//optional 
	bool		full;			//optional 
    long		last_meal_time;
    t_fork 		*first_fork;//left fork
    t_fork 		*second_fork;//right fork
	t_table		*table;
}		t_philo;

struct s_table
{
		long	philo_nbr;
		long	time_to_die;
		long	time_to_eat;
		long	time_to_sleep;
		long	nbr_limit_meals;// {number } || flag -1 
		long	start_simulation;//start time 
		bool	end_simulation;
		bool	all_thread_ready;
		pthread_mutex_t table_mutex;
		t_fork	*fork;//all the forks
		t_philo	*philos;//all the philo

};
/*****input_error.c******/

int input_error(int ac, char **av);

/*****parsing.c*****/

void    parse_input(t_table *table, char **av);

/*****init.c*****/

void    data_init(t_table *table);

/*****safe*****/
void    *safe_malloc(size_t byte);

void    safe_thread_handel(pthread_t *thread, void *(*foo),void *data,t_opcode opcode);
void    safe_mutex_handel(pthread_mutex_t *mutex, t_opcode opcode);

void set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool get_bool(pthread_mutex_t *mutex, bool *value);
long get_long(pthread_mutex_t *mutex, long *value);
void set_long(pthread_mutex_t *mutex, long *dest, long value);
void simulation_finished(t_table *table);

/*******synchro_utils.c*******/
void wait_all_threads(t_table *table);

/********UTILE */
long    gettime(t_time_code time_code);

#endif