/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:10:16 by msalim            #+#    #+#             */
/*   Updated: 2025/01/22 19:54:46 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_data(t_thread_data *thread_data)
{
	pthread_mutex_lock(&thread_data->philo->philo_mutex);
	thread_data->philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&thread_data->philo->philo_mutex);
}

void	*philo_routine(void *args)
{
	t_thread_data	*thread_data;

	thread_data = (t_thread_data *)args;
	set_data(thread_data);
	while (1)
	{
		if (!eating(thread_data))
			break ;
		if (!sleeping(thread_data))
			break ;
		if (!thinking(thread_data))
			break ;
	}
	free(thread_data);
	return (NULL);
}

int	create_thread(t_data *data, t_philo *philo)
{
	t_thread_data	*thread_data;
  t_thread_data	*monitor_data;
  pthread_t		monitor;
	int				i;

	i = 0;
	pthread_mutex_lock(&data->death_mutex);
	data->start_time = get_timestamp();
	pthread_mutex_unlock(&data->death_mutex);
	while (i < data->num_of_philos)
	{
		thread_data = init_thread_args(data, philo);
		if (!thread_data)
			return (-1);
		thread_data->philo = &philo[i];
		if (pthread_create(&philo[i].thread, NULL, philo_routine,
				(void *)thread_data) != 0)
		{
			free(thread_data);
			return (-1);
		}
		i++;
	}
  monitor_data = init_thread_args(data, philo);
	pthread_create(&monitor, NULL, &monitor_routine, (void *)monitor_data);
	for (int i = 0; i < data->num_of_philos; i++)
		pthread_join(philo[i].thread, NULL);
	pthread_join(monitor, NULL);
  free(monitor_data);
	return (0);
}
