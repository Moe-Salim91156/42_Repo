/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:10:16 by msalim            #+#    #+#             */
/*   Updated: 2025/01/18 17:42:49 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	all_philos_have_eaten(t_thread_data *thread_data)
{
	int	i;

	i = 0;
	if (thread_data->data->proper_meals <= 0)
		return (0);
	while (i < thread_data->data->num_of_philos)
	{
		pthread_mutex_lock(&thread_data->philo[i].philo_mutex);
		if (thread_data->philo[i].meals_eaten < thread_data->data->proper_meals)
		{
			pthread_mutex_unlock(&thread_data->philo[i].philo_mutex);
			return (0);
		}
		pthread_mutex_unlock(&thread_data->philo[i].philo_mutex);
		i++;
	}
	pthread_mutex_lock(&thread_data->data->death_mutex);
	thread_data->data->stop_flag = 0;
	pthread_mutex_unlock(&thread_data->data->death_mutex);
	return (1);
}

int	man_im_dead(t_thread_data *thread_data)
{
	long	time_since_last_meal;

	pthread_mutex_lock(&thread_data->philo->philo_mutex);
	time_since_last_meal = get_timestamp() - thread_data->philo->last_meal;
	pthread_mutex_unlock(&thread_data->philo->philo_mutex);
	if (time_since_last_meal >= thread_data->data->time_to_die)
	{
		pthread_mutex_lock(&thread_data->data->printf_mutex);
		pthread_mutex_lock(&thread_data->data->death_mutex);
		if (thread_data->data->stop_flag == 1)
		{
			thread_data->data->stop_flag = 0;
			printf("%ld philo %d died\n", get_timestamp(),
				thread_data->philo->id);
		}
		pthread_mutex_unlock(&thread_data->data->death_mutex);
		pthread_mutex_unlock(&thread_data->data->printf_mutex);
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
		if (all_philos_have_eaten(thread_data))
			break ;
		if (detect_stop(thread_data) == 0)
			break ;
		if (!eating(thread_data) || !sleeping(thread_data)
			|| (!thinking(thread_data)))
			break ;
		if (!man_im_dead(thread_data))
			break ;
		if (all_philos_have_eaten(thread_data))
			break ;
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
	return (0);
}
