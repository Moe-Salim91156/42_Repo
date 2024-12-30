/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:12:25 by msalim            #+#    #+#             */
/*   Updated: 2024/12/30 20:06:20 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/philo.h"

t_philo *init_philo(int num_of_philos)
{
  t_philo *philo;

  philo = malloc(sizeof(t_philo) * num_of_philos);
  philo->id = 0;
  philo->state = NULL;
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

void  create_philos(char **av, t_philo *philo, pthread_mutex_t *forks)
{
  int i = 0;
  int num_of_philos = atoi(av[1]);

  while (i < num_of_philos)
  {
    philo[i].id = i;
    philo[i].left_fork = &forks[i];
    philo[i].right_fork = &forks[(i + 1) % num_of_philos];;
    i++;
  }
}

