/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:31:53 by msalim            #+#    #+#             */
/*   Updated: 2025/01/01 20:06:43 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include  <string.h>

typedef struct  s_philo
{
  int id;
  char  *state;
  pthread_mutex_t *left_fork;
  pthread_mutex_t *right_fork;
} t_philo;

void *philo_lifecycle(void *arg) ;
t_philo *init_philo(int nu);
pthread_mutex_t *init_forks(int num);
void  create_philos(int num, t_philo *philo, pthread_mutex_t *forks);
void  create_thread_philo(int num_of_philos, t_philo *philo);
#endif
