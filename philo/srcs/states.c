/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:39:19 by msalim            #+#    #+#             */
/*   Updated: 2025/01/16 19:25:48 by msalim           ###   ########.fr       */
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
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int eating(t_thread_data *thread_data)
{
    if (thread_data->philo->id % 2 == 0)
    {
        pthread_mutex_lock(thread_data->philo->left_fork);
        printf("%ld philo %d has taken left fork\n", get_timestamp(), thread_data->philo->id);
        pthread_mutex_lock(thread_data->philo->right_fork);
        printf("%ld philo %d has taken right fork\n", get_timestamp(), thread_data->philo->id);
    }
    else
    {
        pthread_mutex_lock(thread_data->philo->right_fork);
        printf("%ld philo %d has taken right fork\n", get_timestamp(), thread_data->philo->id);
        pthread_mutex_lock(thread_data->philo->left_fork);
        printf("%ld philo %d has taken left fork\n", get_timestamp(), thread_data->philo->id);
    }
    printf("%ld philo %d is eating\n", get_timestamp(), thread_data->philo->id);
    usleep(thread_data->data->time_to_eat * 1000);
    pthread_mutex_unlock(thread_data->philo->left_fork);
    pthread_mutex_lock(&thread_data->philo->philo_mutex);
    thread_data->philo->last_meal = get_timestamp();
    pthread_mutex_unlock(&thread_data->philo->philo_mutex);
    printf("%ld philo %d has put down left fork\n", get_timestamp(), thread_data->philo->id);
    pthread_mutex_unlock(thread_data->philo->right_fork);
    printf("%ld philo %d has put down right fork\n", get_timestamp(), thread_data->philo->id);
    return (1);
}

int	thinking(t_thread_data *thread_data)
{
	pthread_mutex_lock(&thread_data->data->printf_mutex);
	printf("%ld philo %d is thinking\n", get_timestamp(),
		thread_data->philo->id);
	pthread_mutex_unlock(&thread_data->data->printf_mutex);
	usleep(100000);
	return (1);
}

int	sleeping(t_thread_data *thread_data)
{
	pthread_mutex_lock(&thread_data->data->printf_mutex);
	printf("%ld philo %d is sleeping\n", get_timestamp(),
		thread_data->philo->id);
	pthread_mutex_unlock(&thread_data->data->printf_mutex);
	usleep(thread_data->data->time_to_sleep * 1000);
	return (1);
}
