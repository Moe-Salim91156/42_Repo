/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:31:53 by msalim            #+#    #+#             */
/*   Updated: 2025/01/22 14:36:36 by msalim           ###   ########.fr       */
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
	long			start_time;
	int				proper_meals;
	int				stop_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	data_mutex;

}					t_data;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals_eaten;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	philo_mutex;
	t_data			*data;

}					t_philo;

typedef struct s_thread_data
{
	t_data			*data;
	t_philo			*philo;
}					t_thread_data;

void				safe_printf(t_thread_data *thread_data, int philosopher_id,
						const char *action);
void				*monitor_routine(void *args);
void				smart_usleep(long duration, long d,t_thread_data *ed);
int					all_philos_have_eaten(t_thread_data *thread_data);
void				eating2(t_thread_data *thread_data);
void				eating1(t_thread_data *thread_data);
void				cleanup(t_data *data, t_philo *philo);
int					detect_stop(t_thread_data *thread_data);
int					man_im_dead(t_philo *philo, t_data *d);
void				debug_forks_init(t_data *data);
int					eating(t_thread_data *thread_data);
int					thinking(t_thread_data *d);
int					sleeping(t_thread_data *d);
void				*init_thread_args(t_data *data, t_philo *philo);
int					create_thread(t_data *data, t_philo *philo);
void				*init_data(int ac, char **av);
void				*init_philo(t_data *data);
void				debug_data_init(t_data *data);
void				debug_mutex_init(t_data *data);
void				debug_philos_init(t_data *data, t_philo *philos);
void				*init_thread_args(t_data *d, t_philo *p);
long				get_timestamp(void);

#endif
