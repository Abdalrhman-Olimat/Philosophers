/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <aeleimat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:03:29 by aeleimat          #+#    #+#             */
/*   Updated: 2025/05/14 20:22:24 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define DEBUG_MODE 0

# include <stdio.h>

// Define color codes
# define RESET "\033[0m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"

// Foreground colors
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[92m"
# define YELLOW "\033[93m"
# define BLUE "\033[94m"
# define MAGENTA "\033[95m"
# define CYAN "\033[96m"
# define WHITE "\033[37m"

// Background colors
# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGYELLOW "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[46m"
# define BGWHITE "\033[47m"
# define BGBRIGHTGREEN "\033[102m"

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DEAD,
}						t_philo_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}						t_opcode;

typedef enum e_time_code
{
	SECOUND,
	MILLISECOUND,
	MICROSECOUND,
}						t_time_code;

typedef struct s_table	t_table;
typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	pthread_t			thread_id;
	int					meals_counter;
	bool				full;
	long				last_meal_time;
	t_fork				*first_fork;
	t_fork				*second_fork;
	pthread_mutex_t		philo_mutex;
	t_table				*table;
}						t_philo;

struct					s_table
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nbr_limit_meals;
	long				start_simulation;
	long				threads_running_nbr;
	bool				end_simulation;
	bool				all_thread_ready;
	pthread_mutex_t		table_mutex;
	pthread_mutex_t		write_mutex;
	pthread_t			monitor;
	t_fork				*fork;
	t_philo				*philos;
};
/*****input_error.c******/

int						input_error(int ac, char **av);

/*****parsing.c*****/

void					parse_input(t_table *table, char **av);

/*****init.c*****/

int						data_init(t_table *table);

/*****safe*****/
int						*safe_malloc(size_t byte);

int						safe_thread_handel(pthread_t *thread,
							void *(*foo)(void *), void *data, t_opcode opcode);
void					safe_mutex_handel(pthread_mutex_t *mutex,
							t_opcode opcode);

void					set_bool(pthread_mutex_t *mutex, bool *dest,
							bool value);
bool					get_bool(pthread_mutex_t *mutex, bool *value);
long					get_long(pthread_mutex_t *mutex, long *value);
void					set_long(pthread_mutex_t *mutex, long *dest,
							long value);
bool					simulation_finished(t_table *table);

/*******synchro_utils.c*******/
void					wait_all_threads(t_table *table);

/********UTILE */
long					gettime(t_time_code time_code);

void					precise_usleep(long usec, t_table *table);
void					write_status(t_philo_status status, t_philo *philo,
							bool debug);
int						dinner_start(t_table *table);
bool					all_thread_running(pthread_mutex_t *mutex,
							long *threads, long philo_nbr);
void					increase_long(pthread_mutex_t *mutex, long *value);
void					*monitor_dinner(void *data);
void					clean(t_table *table);
void					unsynchronize_philos(t_philo *philo);
void					think(t_philo *philo, bool pre_simulation);
void					eat(t_philo *philo);
void					*long_philo(void *data);
void					think(t_philo *philo, bool pre_simulation);
void					*dinner_simulation(void *data);
#endif