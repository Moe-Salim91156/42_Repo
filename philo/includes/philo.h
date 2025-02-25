/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:31:53 by msalim            #+#    #+#             */
/*   Updated: 2025/01/27 15:13:13 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
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

int					ft_strcmp(const char *s1, char *s2);
int					ft_atoi(const char *s);
long				ft_atol(const char *str);
int					lock_fork_even(t_philo *philo);
int					lock_fork_odd(t_philo *philo);
void				debug_all(t_philo *p);
void				kill_all_philo(t_philo *philo);
void				debug_last_meal(t_philo *p);
void				smart_usleep(t_philo *philo, long start_time,
						long duration);
void				safe_printf(t_philo *t, int philosopher_id,
						const char *action);
void				*monitor_routine(void *args);
int					all_philos_have_eaten(t_thread_data *thread_data);
int					eating2(t_philo *phlo);
int					eating1(t_philo *phlo);
void				cleanup(t_data *data, t_philo *philo);
int					detect_stop(t_philo *philo);
int					man_im_dead(t_philo *philo);
void				debug_forks_init(t_data *data);
int					eating(t_philo *ph);
int					thinking(t_philo *d);
int					sleeping(t_philo *d);
void				*init_thread_args(t_data *data, t_philo *philo);
int					create_thread(t_data *data, t_philo *philo);
void				*init_data(int ac, char **av);
void				*init_philo(t_data *data);
void				*init_thread_args(t_data *d, t_philo *p);
long				get_timestamp(void);
void				cleanup_mutexes(t_data *d);
void				cleanup_philos(t_philo *p, t_data *data);

#endif
