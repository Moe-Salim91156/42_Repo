/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:31:53 by msalim            #+#    #+#             */
/*   Updated: 2025/01/16 16:45:52 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
typedef struct s_data
{
	int				num_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				proper_meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	death_mutex;


}					t_data;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals_eaten;
	long			last_meal;
  int       stop_flag;
	pthread_mutex_t	philo_mutex;
	t_data			*data;

}					t_philo;

typedef struct s_monitor_data
{
    t_data *data;
    t_philo *philos;
} t_monitor_data;

void  *init_data(int ac,char **av);
void  *init_philo(t_data *data);
void debug_data_init(t_data *data);
void debug_mutex_init(t_data *data);
void debug_philos_init(t_data *data, t_philo *philos);

#endif
