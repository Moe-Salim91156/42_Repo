/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:10:16 by msalim            #+#    #+#             */
/*   Updated: 2025/01/20 19:29:42 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	man_im_dead(t_thread_data *thread_data)
{
	long	time_since_last_meal;

	pthread_mutex_lock(thread_data->philo->philo_mutex);
	time_since_last_meal = get_timestamp() - thread_data->philo->last_meal;
	if (time_since_last_meal >= thread_data->data->time_to_die)
  {
    pthread_mutex_unlock(thread_data->philo->philo_mutex);
		return (0);
  }
	return (1);
}

void	*philo_routine(void *args)
{
	t_thread_data	*thread_data;

	thread_data = (t_thread_data *)args;
	while (1)
	{
    if (!eating(thread_data))
      break;
    if (!sleeping(thread_data))
      break;
    if (!thinking(thread_data))
      break;
  }
	free(thread_data);
	return (NULL);
}

int	create_thread(t_data *data, t_philo *philo)
{
	t_thread_data	*thread_data;
	int				i;

	i = 0;
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
    for (int i = 0; i < data->num_of_philos; i++)
		pthread_join(philo[i].thread, NULL);
	return (0);
}
