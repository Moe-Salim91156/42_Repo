/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:31:53 by msalim            #+#    #+#             */
/*   Updated: 2025/01/02 19:41:24 by msalim           ###   ########.fr       */
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
  int       sleep_time;
  int       eating_time;
  int       thinking;
}					t_philo;
typedef struct s_thread_args {
    pthread_mutex_t *forks;
    t_philo *philo;
    int num_of_philos;
} t_thread_args;

void				*philo_lifecycle(void *args);
t_philo				*init_philo(int nu,char **a);
pthread_mutex_t		*init_forks(int num);
void				create_philos(int num, t_philo *philo,
						pthread_mutex_t *forks);
void create_thread_philo(pthread_mutex_t *forks, t_philo *philo, int num_of_philos);
//void				create_thread_philo(int num_of_philos, t_philo *philo);
#endif
