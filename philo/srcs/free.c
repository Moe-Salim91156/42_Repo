/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:48:09 by msalim            #+#    #+#             */
/*   Updated: 2025/01/21 19:50:57 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_threads(pthread_t *threads, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	cleanup_forks(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (i < data->num_of_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
}

void	cleanup_philos(t_philo *philo, t_data *data)
{
	int	i;

	if (philo)
	{
		i = 0;
		while (i < data->num_of_philos)
		{
			pthread_mutex_destroy(&philo[i].philo_mutex);
			i++;
		}
		free(philo);
	}
}

void	cleanup_mutexes(t_data *data)
{
	pthread_mutex_destroy(&data->printf_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}

void	cleanup(t_data *data, t_philo *philo)
{
	if (data)
	{
		cleanup_forks(data);
		cleanup_mutexes(data);
		cleanup_philos(philo, data);
		free(data);
	}
}
