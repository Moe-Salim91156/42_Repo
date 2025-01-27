/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:49:56 by msalim            #+#    #+#             */
/*   Updated: 2025/01/27 15:10:31 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	smart_usleep(t_philo *philo, long start_time, long duration)
{
	long	total;

	total = start_time + duration;
	while (get_timestamp() < total && detect_stop(philo))
	{
		if (!man_im_dead(philo))
		{
			break ;
		}
		usleep(100);
	}
}

void	safe_printf(t_philo *philo, int philosopher_id, const char *action)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->printf_mutex);
	pthread_mutex_lock(&philo->data->data_mutex);
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->stop_flag == 0 && ft_strcmp(action, "has died\n") != 0)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		pthread_mutex_unlock(&philo->data->data_mutex);
		pthread_mutex_unlock(&philo->data->printf_mutex);
		return ;
	}
	timestamp = get_timestamp() - philo->data->start_time;
	printf("%ld philo %d %s", timestamp, philosopher_id, action);
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_unlock(&philo->data->data_mutex);
	pthread_mutex_unlock(&philo->data->printf_mutex);
}

int	eating1(t_philo *philo)
{
	if (!man_im_dead(philo))
	{
		return (0);
	}
	pthread_mutex_lock(&philo->philo_mutex);
	safe_printf(philo, philo->id, "is eating\n");
	philo->meals_eaten++;
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->philo_mutex);
	smart_usleep(philo, get_timestamp(), philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (1);
}

int	eating2(t_philo *philo)
{
	if (!man_im_dead(philo))
	{
		return (0);
	}
	pthread_mutex_lock(&philo->philo_mutex);
	safe_printf(philo, philo->id, "is eating\n");
	philo->meals_eaten++;
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->philo_mutex);
	smart_usleep(philo, get_timestamp(), philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}
