/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:12:25 by msalim            #+#    #+#             */
/*   Updated: 2025/01/01 18:23:05 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/philo.h"

t_philo *init_philo(int num_of_philos)
{
  int i;
  t_philo *philo;

  i = 0;
  philo = malloc(sizeof(t_philo) * num_of_philos);
  while (i < num_of_philos)
  {
    philo[i].id = i;
    //philo[i].state= NULL;
    philo[i].left_fork = NULL;
    philo[i].right_fork = NULL;
    i++;
  }
  return (philo);
}

pthread_mutex_t  *init_forks(int num_of_philos)
{
  int i;
  pthread_mutex_t *forks;

  i = 0;
  forks = malloc(sizeof(pthread_mutex_t) * num_of_philos);
  if (!forks)
  {
    //maybe free soemthing here;
    exit(1);
  }
  while (i < num_of_philos)
  {
    pthread_mutex_init(&forks[i], NULL);
    i++;
  }
  return (forks);
}

void  create_philos(int num_of_philos, t_philo *philo, pthread_mutex_t *forks)
{
  int i = 0;

  while (i < num_of_philos)
  {
    philo[i].id = i;
    philo[i].left_fork = &forks[i];
    philo[i].right_fork = &forks[(i + 1) % num_of_philos];;
    i++;
  }
}

