/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:01:14 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/21 13:20:20 by rwintgen         ###   ########.fr       */
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

# define MSG_MTX_ACTION "philo: invalid mutex action\n"
# define MSG_MTX_VAL "philo: invalid mutex value\n"
# define MSG_MTX_ATTR_VAL "philo: invalid attribute value\n"
# define MSG_MTX_DDLK "philo: deadlock detected\n"
# define MSG_MTX_PERM "philo: thread does not lock mutex\n"
# define MSG_MTX_MEM "philo: mutex memory allocation failed\n"
# define MSG_MTX_BUSY "philo: mutex is already locked\n"

# define MSG_THR_ACTION "philo: invalid thread action"
# define MSG_THR_AGAIN "philo: no resources to create additional threads\n"
# define MSG_THR_PERM "philo: invalid caller permissions\n"
# define MSG_THR_VAL "philo: invalid thread value\n"
# define MSG_THR_SRCH "philo: could not find thread pointed by specified ID\n"
# define MSG_THR_DDLK "philo: deadlock detected\n"

/************************ STRUCTURES ************************/

typedef pthread_mutex_t	t_mutex;
typedef long			t_time;
typedef struct s_table	t_table;

typedef enum e_errs
{
	E_ARGC = 2,
	E_ARGV,
	E_MTX_ACTION,
	E_ATTR_VAL,
	E_MTX_VAL,
	E_MTX_DDLK,
	E_MTX_PERM,
	E_MTX_MEM,
	E_MTX_BUSY,
	E_THR_ACTION,
	E_THR_AGAIN,
	E_THR_PERM,
	E_THR_VAL,
	E_THR_SRCH,
	E_THR_DDLK
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

typedef struct s_fork
{
	int		id;
	t_mutex	fork;
}				t_fork;

typedef struct s_philo
{
	int			id;
	int			nb_meals;
	bool		full;
	t_time		last_meal;

	t_fork		*left_fork;
	t_fork		*right_fork;

	pthread_t	thrd_id;

	t_table		*table;
}				t_philo;

typedef struct s_table
{
	long	nb_philo;
	t_time	time_to_die;
	t_time	time_to_eat;
	t_time	time_to_sleep;

	long	nb_meals;

	t_time	start;
	bool	finish;

	t_fork	*forks;
	t_philo	*philos;
}				t_table;

/************************ PROTOTYPES ************************/

void	debug_parsing(t_table table);

size_t	ph_nblen(const char *s);
int		ph_strncmp(const char *s1, const char *s2, size_t n);
void	err_exit(int err, char *msg);
void	set_table(int argc, char **argv, t_table *table);
bool	valid_arg(char *arg);
long	ph_atol(char *str);
bool	is_num(char c);
bool	is_whitespace(char c);
size_t	ph_strlen(const char *str);
void	welcome_guests(t_table *table);
void	exit_if_err(int err, t_action action);

#endif