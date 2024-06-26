/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:53:48 by rwintgen          #+#    #+#             */
/*   Updated: 2024/06/26 17:04:41 by rwintgen         ###   ########.fr       */
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
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
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

/************************ STRUCTURES ************************/

typedef enum e_errs
{
	E_ARGC = 2,
	E_ARGV,
	E_MALLOC,
	E_GETTOD,
	E_UNIT
}				t_errs;

typedef struct s_philo
{
	int				id;
	long			meals_count;
	bool			full;
	long			last_meal_time;
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
	bool			end_simulation;
	long			running_threads_count;
	t_philo			*philos;
}				t_table;

/************************ PROTOTYPES ************************/

#endif PHILO_BONUS_H