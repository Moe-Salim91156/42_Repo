/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:31:53 by msalim            #+#    #+#             */
/*   Updated: 2025/01/05 17:36:08 by msalim           ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	char			*state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*printf_mutex;
	long			last_meal;
	long			sleep_time;
	long			eating_time;
	long			thinking;
	long			time_to_die;
	long			proper_meals;
	long			meals_eaten;
}					t_philo;

typedef struct s_thread_args
{
	pthread_mutex_t	*forks;
	int				num_of_philos;
	t_philo			*philo;
}					t_thread_args;

typedef struct s_input_args
{
	int				ac;
	char			**av;
}					t_input_args;

void				*philo_lifecycle(void *args);
t_philo				*init_philo(int nu, t_input_args args);
pthread_mutex_t		*init_forks(int num);
void				create_philos(int num, t_philo *philo,
						pthread_mutex_t *forks, t_input_args args);
void				create_thread_philo(pthread_mutex_t *forks, t_philo *philo,
						int num_of_philos);
int					eating(int num_of_philos, pthread_mutex_t *forks,
						t_philo *philo);
void				think(t_philo *philo);
long				get_timestamp(void);
void				sleep_philo(t_philo *philo);
int					odd_philo_logic(int num_of_philos, pthread_mutex_t *forks,
						t_philo *philo, long times);
int					even_philo_logic(int num_of_philos, pthread_mutex_t *forks,
						t_philo *philo, long times);
int					general_eating_logic(int num_of_philos,
						pthread_mutex_t *forks, t_philo *philo, long times);
int					has_philo_died(t_philo *philo);
void				join_threads(pthread_t *threads, int num_of_philos);
void ft_putlong_fd(long n, int fd);
void	ft_putnbr_fd(int n, int fd);
void  ft_putstr_fd(char *s, int fd);
void print_logs(long time, t_philo *philo, char *message);
#endif
