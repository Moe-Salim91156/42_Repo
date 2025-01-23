/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:49:56 by msalim            #+#    #+#             */
/*   Updated: 2025/01/23 19:23:32 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	smart_usleep(t_philo *philo, long start_time, long duration)
{
	long	total;

	total = start_time + duration;
	pthread_mutex_lock(&philo->data->death_mutex);
	while (philo->data->stop_flag && get_timestamp() < total)
		usleep(1);
	pthread_mutex_unlock(&philo->data->death_mutex);
}

void	safe_printf(t_philo *philo, int philosopher_id, const char *action)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->data_mutex);
	pthread_mutex_lock(&philo->data->printf_mutex);
	timestamp = get_timestamp() - philo->data->start_time;
	printf("%ld philo %d %s", timestamp, philosopher_id, action);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	pthread_mutex_unlock(&philo->data->data_mutex);
}

void	eating1(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	safe_printf(philo, philo->id, "has taken a fork\n");
	safe_printf(philo, philo->id, "has taken a fork\n");
	safe_printf(philo, philo->id, "is eating\n");
	pthread_mutex_lock(&philo->philo_mutex);
	philo->meals_eaten++;
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->philo_mutex);
	smart_usleep(philo, get_timestamp(), philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	eating2(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	safe_printf(philo, philo->id, "has taken a fork\n");
	safe_printf(philo, philo->id, "has taken a fork\n");
  safe_printf(philo, philo->id, "is eating\n");
	pthread_mutex_lock(&philo->philo_mutex);
	philo->meals_eaten++;
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->philo_mutex);
	smart_usleep(philo, get_timestamp(), philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
