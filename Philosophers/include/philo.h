/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:01:14 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/23 13:43:42 by rwintgen         ###   ########.fr       */
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

# define RST "\x1B[0m"
# define W "\x1B[37m"
# define G "\x1B[32m"
# define B "\x1B[34m"
# define C "\x1B[36m"
# define R "\x1B[31m"

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

typedef pthread_mutex_t	t_mutex;
typedef long			t_time;
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
	TAKE_FORK_ONE,
	TAKE_FORK_TWO,
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
	int		id;
	t_mutex	mutex;
}				t_fork;

typedef struct s_philo
{
	int			id;
	int			nb_meals;
	bool		full;
	t_time		last_meal;

	t_fork		*fork_one;
	t_fork		*fork_two;
	t_mutex		mutex;

	pthread_t	thrd_id;

	t_table		*table;
}				t_philo;

typedef struct s_table
{
	long		nb_philo;
	t_time		time_to_die;
	t_time		time_to_eat;
	t_time		time_to_sleep;

	long		nb_threads;

	long		nb_meals;
	bool		threads_ready;

	t_time		start;
	bool		finish;

	t_fork		*forks;
	t_philo		*philos;

	t_mutex		rd_mutex;
	t_mutex		wr_mutex;

	pthread_t	monitoring;
}				t_table;

/************************ PROTOTYPES ************************/

void	debug_parsing(t_table table);
void	debug_init(t_table table);

void	thread_action(pthread_t *thread, void *(*func)(void *), void *data, t_action action);
bool	all_threads_running(t_mutex *mutex, long nb_threads, long nb_philos);
int		ph_strncmp(const char *s1, const char *s2, size_t n);
void	set_table(int argc, char **argv, t_table *table);
void	set_bool(t_mutex *mutex, bool *var, bool value);
void	set_long(t_mutex *mutex, long *var, long value);
void	mutex_action(t_mutex *mutex, t_action action);
void	print_status(t_philo *philo, t_state state);
void	increment_long(t_mutex *mutex, long *var);
void	ph_usleep(t_time time, t_table *table);
void	exit_if_err(int err, t_action action);
bool	get_bool(t_mutex *mutex, bool *var);
long	get_long(t_mutex *mutex, long *var);
bool	dinner_finished(t_table *table);
void	welcome_guests(t_table *table);
void	err_exit(int err, char *msg);
size_t	ph_strlen(const char *str);
void	eat_dinner(t_table *table);
void	wait_all(t_table *table);
void	*ph_malloc(size_t size);
size_t	ph_nblen(const char *s);
t_time	get_time(t_unit unit);
bool	is_whitespace(char c);
bool	valid_arg(char *arg);
void	*monitor(void *param);
long	ph_atol(char *str);
bool	is_num(char c);

#endif