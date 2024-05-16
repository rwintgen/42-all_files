/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:01:14 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/16 16:37:03 by rwintgen         ###   ########.fr       */
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

/************************** DEFINES *************************/

# define NO_MEALS -1
# define ERROR -1

# define E_ARGC 1
# define E_ARGV 2

# define MSG_USAGE "Usage: ./philo nb_philo time_to_die time_to_eat\
 time_to_sleep [meals_needed]\n"
# define MSG_NUM "philo: arguments must be positive integers\n"

/************************ STRUCTURES ************************/

typedef pthread_mutex_t	t_mutex;
typedef long			t_time;
typedef struct s_table	t_table;

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

	t_fork		*leph_fork;
	t_fork		*right_fork;

	pthread_t	t_id;

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

size_t	ph_nblen(const char *s);
int		ph_strncmp(const char *s1, const char *s2, size_t n);
void	err_exit(int err, char *msg);
void	set_table(int argc, char **argv, t_table *table);
bool	valid_arg(char *arg);
long	ph_atol(char *str);
bool	is_num(char c);
bool	is_whitespace(char c);
size_t	ph_strlen(const char *str);

#endif