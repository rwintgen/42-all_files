/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:53:48 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/01 12:09:47 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

/************************* LIBRARIES ************************/

# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>

/************************** DEFINES *************************/

# define NO_MEALS -1
# define ERROR -1

# define MSG_USAGE "Usage: ./philo nb_philo time_to_die time_to_eat\
 time_to_sleep [meals_needed]\n"
# define MSG_NUM "philo: arguments must be positive integers (limit: INT_MAX)\n"
# define MSG_MALLOC "philo: memory allocation failed\n"
# define MSG_GETTOD "philo: could not get time of day\n"
# define MSG_UNIT "philo: invalid time unit\n"
# define MSG_THRD "philo: thread creation failed\n"

/************************ STRUCTURES ************************/

typedef struct s_table	t_table;

typedef enum e_errs
{
	E_ARGC = 2,
	E_ARGV,
	E_MALLOC,
	E_GETTOD,
	E_UNIT,
	E_THRD
}				t_errs;

typedef enum e_unit
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS
}				t_unit;

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	TAKE_FORK,
	DEAD
}				t_state;

typedef struct s_philo
{
	int				id;
	bool			full;
	long			meals_count;
	long			last_meal;

	pid_t			pid;
	sem_t			*sem_last_meal;
	t_table			*table;
}				t_philo;

typedef struct s_table
{
	long			philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_needed;
	long			start_time;

	pthread_t		death_monitor;
	sem_t			*end_simulation;
	sem_t			*sem_forks;
	sem_t			*sem_print;
	t_philo			*philos;
}				t_table;

/************************ PROTOTYPES ************************/

void	err_exit(int err, char *msg);
void	err_free_exit(t_table *table, int err, char *msg);
void	parse_input(int argc, char **argv, t_table *table);
long	ph_atol(char *str);
size_t	ph_nblen(const char *s);
size_t	ph_strlen(const char *str);
bool	is_num(char c);
bool	is_whitespace(char c);
void	ph_usleep(long time);
long	get_time(t_unit unit);
void	init_semaphores(t_table *table);
void	init_philos(t_table *table);
char	*ph_itoa(int n);
char	*ph_strjoin(char const *s1, char const *s2);
void	*wait_death(void *param);
int		start_processes(t_table *table);
void	print_status(t_philo *philo, t_state state);
int		wait_all_processes(t_table *table);
void	free_all(t_table *table);

#endif