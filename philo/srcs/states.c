/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:39:19 by msalim            #+#    #+#             */
/*   Updated: 2025/01/20 19:29:11 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_timestamp(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return (-1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
int detect_stop(t_thread_data *thread_data)
{
    pthread_mutex_lock(&thread_data->data->death_mutex);
    int stop = (thread_data->data->stop_flag != 0);
    pthread_mutex_unlock(&thread_data->data->death_mutex);
    return stop;
}

int	eating(t_thread_data *thread_data)
{
	if (detect_stop(thread_data) == 0)
		return (0);
	if (thread_data->philo->id % 2 == 0)
		eating1(thread_data);
	else
		eating2(thread_data);
	pthread_mutex_lock(thread_data->philo->philo_mutex);
	thread_data->philo->meals_eaten++;
	thread_data->philo->last_meal = get_timestamp();
	pthread_mutex_unlock(thread_data->philo->philo_mutex);
	return (1);
}

int	thinking(t_thread_data *thread_data)
{
	if (detect_stop(thread_data) == 0)
		return (0);
	pthread_mutex_lock(&thread_data->data->printf_mutex);
	printf("%ld philo %d is thinking\n", get_timestamp(),
		thread_data->philo->id);
	pthread_mutex_unlock(&thread_data->data->printf_mutex);
	usleep(10000);
	return (1);
}

int	sleeping(t_thread_data *thread_data)
{
	if (detect_stop(thread_data) == 0)
		return (0);
	pthread_mutex_lock(&thread_data->data->death_mutex);
	if (thread_data->data->stop_flag == 0)
	{
		pthread_mutex_unlock(&thread_data->data->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(&thread_data->data->death_mutex);
	pthread_mutex_lock(&thread_data->data->printf_mutex);
	printf("%ld philo %d is sleeping\n", get_timestamp(),
		thread_data->philo->id);
	pthread_mutex_unlock(&thread_data->data->printf_mutex);
	usleep(thread_data->data->time_to_sleep * 1000);
	return (1);
}
