/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:08:13 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/20 16:31:03 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/************************* LIBRARIES ************************/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>

/************************** DEFINES *************************/

# define NO_MEALS -1
# define ERROR -1

# define MSG_USAGE "Usage: ./philo nb_philo time_to_die time_to_eat\
 time_to_sleep [meals_needed]\n"
# define MSG_NUM "philo: arguments must be positive integers (limit: INT_MAX)\n"
# define MSG_MALLOC "philo: memory allocation failed\n"

# define MSG_MTX_ACTION "philo: invalid mutex action\n"
# define MSG_MTX_VAL "philo: invalid mutex value\n"
# define MSG_MTX_ATTR_VAL "philo: invalid attribute value\n"
# define MSG_MTX_DDLK "philo: deadlock detected\n"
# define MSG_MTX_PERM "philo: thread does not lock mutex\n"
# define MSG_MTX_MEM "philo: mutex memory allocation failed\n"
# define MSG_MTX_BUSY "philo: mutex is already locked\n"

# define MSG_THR_ACTION "philo: invalid thread action"
# define MSG_THR_VAL "philo: invalid thread value\n"
# define MSG_THR_ATTR_VAL "philo: invalid attribute value\n"
# define MSG_THR_DDLK "philo: deadlock detected\n"
# define MSG_THR_PERM "philo: invalid caller permissions\n"
# define MSG_THR_AGAIN "philo: no resources to create additional threads\n"
# define MSG_THR_SRCH "philo: could not find thread pointed by specified ID\n"

# define MSG_GETTOD "philo: could not get time of day\n"
# define MSG_UNIT "philo: invalid time unit\n"

/************************ STRUCTURES ************************/

typedef struct s_table	t_table;

typedef enum e_errs
{
	E_ARGC = 2,
	E_ARGV,
	E_MALLOC,
	E_MTX_ACTION,
	E_MTX_ATTR_VAL,
	E_MTX_VAL,
	E_MTX_DDLK,
	E_MTX_PERM,
	E_MTX_MEM,
	E_MTX_BUSY,
	E_THR_ACTION,
	E_THR_ATTR_VAL,
	E_THR_VAL,
	E_THR_DDLK,
	E_THR_PERM,
	E_THR_AGAIN,
	E_THR_SRCH,
	E_GETTOD,
	E_UNIT
}				t_errs;

typedef enum e_action
{
	LOCK,
	UNLOCK,
	DESTROY,
	INIT,
	CREATE,
	JOIN,
	DETACH
}				t_action;

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	TAKE_FORK,
	DEAD
}				t_state;

typedef enum e_unit
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS
}				t_unit;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philo
{
	int				id;
	long			meals_count;
	bool			full;
	long			last_meal_time;
	t_fork			*fork_one;
	t_fork			*fork_two;
	t_table			*table;
	pthread_t		thread_id;
	pthread_mutex_t	mutex;
}				t_philo;

typedef struct s_table
{
	long			philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_needed;

	long			start_time;
	bool			end_simulation;
	bool			all_threads_ready;
	long			running_threads_count;
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		monitor;
	pthread_mutex_t	table_mutex;
	pthread_mutex_t	print_mutex;
}				t_table;


/************************ PROTOTYPES ************************/

bool	valid_arg(char *arg);
bool	is_num(char c);
bool	is_whitespace(char c);
void	parse_input(int argc, char **argv, t_table *table);

long	ph_atol(char *str);
size_t	ph_nblen(const char *s);
size_t	ph_strlen(const char *str);
void	ph_usleep(long time, t_table *table);

void	err_exit(int err, char *msg);
long	get_time(t_unit unit);

void	thread_action(pthread_t *thread, void *(*func)(void *), void *data, t_action action);
void	mutex_action(pthread_mutex_t *mutex, t_action action);

void	init_data(t_table *table);

void	start_dinner(t_table *table);
void	*dinner_routine(void *data);

bool	get_bool(pthread_mutex_t *mutex, bool *var);
long	get_long(pthread_mutex_t *mutex, long *var);
bool	dinner_finished(t_table *table);

void	set_bool(pthread_mutex_t *mutex, bool *var, bool value);
void	set_long(pthread_mutex_t *mutex, long *var, long value);
void	increment_long(pthread_mutex_t *mutex, long *var);

void	wait_all_threads(t_table *table);

void	print_status(t_philo *philo, t_state state);

bool	all_threads_running(pthread_mutex_t *mutex, long nb_threads, long nb_philos);

#endif