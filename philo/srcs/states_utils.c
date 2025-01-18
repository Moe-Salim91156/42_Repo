/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:49:56 by msalim            #+#    #+#             */
/*   Updated: 2025/01/18 17:40:51 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	eating1(t_thread_data *thread_data)
{
	pthread_mutex_lock(thread_data->philo->left_fork);
	pthread_mutex_lock(thread_data->philo->right_fork);
	pthread_mutex_lock(&thread_data->data->printf_mutex);
	printf("%ld philo %d has taken fork\n", get_timestamp(),
		thread_data->philo->id);
	printf("%ld philo %d has taken fork\n", get_timestamp(),
		thread_data->philo->id);
	pthread_mutex_unlock(&thread_data->data->printf_mutex);
	pthread_mutex_lock(&thread_data->data->printf_mutex);
	printf("%ld philo %d is eating\n", get_timestamp(), thread_data->philo->id);
	usleep(thread_data->data->time_to_eat * 1000);
	pthread_mutex_unlock(&thread_data->data->printf_mutex);
	pthread_mutex_unlock(thread_data->philo->left_fork);
	pthread_mutex_unlock(thread_data->philo->right_fork);
}

void	eating2(t_thread_data *thread_data)
{
	pthread_mutex_lock(thread_data->philo->right_fork);
	pthread_mutex_lock(thread_data->philo->left_fork);
	pthread_mutex_lock(&thread_data->data->printf_mutex);
	printf("%ld philo %d has taken fork\n", get_timestamp(),
		thread_data->philo->id);
	printf("%ld philo %d has taken fork\n", get_timestamp(),
		thread_data->philo->id);
	pthread_mutex_unlock(&thread_data->data->printf_mutex);
	pthread_mutex_lock(&thread_data->data->printf_mutex);
	printf("%ld philo %d is eating\n", get_timestamp(), thread_data->philo->id);
	usleep(thread_data->data->time_to_eat * 1000);
	pthread_mutex_unlock(&thread_data->data->printf_mutex);
	pthread_mutex_unlock(thread_data->philo->right_fork);
	pthread_mutex_unlock(thread_data->philo->left_fork);
}
