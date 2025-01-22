/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:49:56 by msalim            #+#    #+#             */
/*   Updated: 2025/01/22 19:19:09 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	safe_printf(t_thread_data *thread_data, int philosopher_id,
		const char *action)
{
	long	timestamp;

	pthread_mutex_lock(&thread_data->data->data_mutex);
	timestamp = get_timestamp() - thread_data->data->start_time;
	printf("%ld philo %d %s", timestamp, philosopher_id, action);
	pthread_mutex_unlock(&thread_data->data->data_mutex);   // Unlock the mutex
}

void eating1(t_thread_data *thread_data)
{
    pthread_mutex_lock(thread_data->philo->left_fork);
    pthread_mutex_lock(thread_data->philo->right_fork);

	  pthread_mutex_lock(&thread_data->data->printf_mutex); // Unlock the mutex
    safe_printf(thread_data, thread_data->philo->id, "has taken a fork\n");
    pthread_mutex_unlock(&thread_data->data->printf_mutex); // Unlock the mutex
	  pthread_mutex_lock(&thread_data->data->printf_mutex); // Unlock the mutex
    safe_printf(thread_data, thread_data->philo->id, "has taken a fork\n");
    pthread_mutex_unlock(&thread_data->data->printf_mutex); // Unlock the mutex
    pthread_mutex_lock(&thread_data->philo->philo_mutex);
    safe_printf(thread_data, thread_data->philo->id, "is eating\n");
    pthread_mutex_unlock(&thread_data->philo->philo_mutex);
    pthread_mutex_lock(&thread_data->philo->philo_mutex);
    thread_data->philo->meals_eaten++;
    thread_data->philo->last_meal = get_timestamp();
    pthread_mutex_unlock(&thread_data->philo->philo_mutex);
    smart_usleep(get_timestamp(), thread_data->data->time_to_eat,thread_data);
    pthread_mutex_unlock(thread_data->philo->right_fork);
    pthread_mutex_unlock(thread_data->philo->left_fork);
}
void eating2(t_thread_data *thread_data)
{
    pthread_mutex_lock(thread_data->philo->right_fork);
    pthread_mutex_lock(thread_data->philo->left_fork);

	  pthread_mutex_lock(&thread_data->data->printf_mutex); // Unlock the mutex
    safe_printf(thread_data, thread_data->philo->id, "has taken a fork\n");
    pthread_mutex_unlock(&thread_data->data->printf_mutex); // Unlock the mutex
	  pthread_mutex_lock(&thread_data->data->printf_mutex); // Unlock the mutex
    safe_printf(thread_data, thread_data->philo->id, "has taken a fork\n");
    pthread_mutex_unlock(&thread_data->data->printf_mutex); // Unlock the mutex
    pthread_mutex_lock(&thread_data->philo->philo_mutex);
    safe_printf(thread_data, thread_data->philo->id, "is eating\n");
    pthread_mutex_unlock(&thread_data->philo->philo_mutex);
    pthread_mutex_lock(&thread_data->philo->philo_mutex);
    thread_data->philo->meals_eaten++;
    thread_data->philo->last_meal = get_timestamp();
    pthread_mutex_unlock(&thread_data->philo->philo_mutex);
    smart_usleep(get_timestamp(), thread_data->data->time_to_eat,thread_data);
    pthread_mutex_unlock(thread_data->philo->left_fork);
    pthread_mutex_unlock(thread_data->philo->right_fork);
}

