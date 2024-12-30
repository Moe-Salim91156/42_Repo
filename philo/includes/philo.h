/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:31:53 by msalim            #+#    #+#             */
/*   Updated: 2024/12/30 19:56:20 by msalim           ###   ########.fr       */
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

t_philo *init_philo();
pthread_mutex_t *init_forks(int num);
void  create_philos(char **av, t_philo *philo, pthread_mutex_t *forks);
#endif
