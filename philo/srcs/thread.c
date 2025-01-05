/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:23:44 by msalim            #+#    #+#             */
/*   Updated: 2025/01/05 18:39:12 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_lifecycle(void *args)
{
	t_thread_args	*thread_args;
	pthread_mutex_t	*forks;
	t_philo			*philo;
	int				num_of_philos;

	thread_args = (t_thread_args *)args;
	forks = thread_args->forks;
	philo = thread_args->philo;
	num_of_philos = thread_args->num_of_philos;
	while (1)
	{
		think(philo);
		if (eating(num_of_philos, forks, philo) == 1)
			philo->meals_eaten++;
		sleep_philo(philo);
		if (has_philo_died(philo) == 1)
			exit(1);
	}
	return (NULL);
}

void	create_thread_philo(pthread_mutex_t *forks, t_philo *philos,
		int num_of_philos)
{
	pthread_t		*threads;
	t_thread_args	*thread_args;
	int				i;

	i = 0;
	threads = malloc(num_of_philos * sizeof(pthread_t));
	if (!threads)
		return ;
	thread_args = malloc(num_of_philos * sizeof(t_thread_args));
	if (!thread_args)
	{
		free(threads);
		return ;
	}
	while (i < num_of_philos)
	{
		thread_args[i].forks = forks;
		thread_args[i].philo = &philos[i];
		thread_args[i].num_of_philos = num_of_philos;
		if (pthread_create(&threads[i], NULL, philo_lifecycle,
				&thread_args[i]) != 0)
		{
			free(threads);
			free(thread_args);
			return ;
		}
		i++;
	}
	join_threads(threads, num_of_philos);
	return ;
}
