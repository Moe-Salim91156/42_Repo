/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:39:19 by msalim            #+#    #+#             */
/*   Updated: 2025/01/22 19:22:13 by msalim           ###   ########.fr       */
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
void	smart_usleep(long start_time, long duration,t_thread_data *thread_data)
{
	long	total;

	total = start_time + duration;
  pthread_mutex_lock(&thread_data->data->death_mutex);
	while (thread_data->data->stop_flag && get_timestamp() < total)
		usleep(1);
  pthread_mutex_unlock(&thread_data->data->death_mutex);
}

int	detect_stop(t_thread_data *thread_data)
{
	pthread_mutex_lock(&thread_data->data->death_mutex);
	if (thread_data->data->stop_flag == 0)
	{
		pthread_mutex_unlock(&thread_data->data->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(&thread_data->data->death_mutex);
	return (1);
}

int	eating(t_thread_data *thread_data)
{
  if (!detect_stop(thread_data))
      return (0);
	if (thread_data->philo->id % 2 == 0)
		eating1(thread_data);
	else
		eating2(thread_data);
	return (1);
}

int	thinking(t_thread_data *thread_data)
{
  if (!detect_stop(thread_data))
    return (0);
	safe_printf(thread_data, thread_data->philo->id, "is thinking\n");
  usleep(100);
	return (1);
}

int	sleeping(t_thread_data *thread_data)
{
	if (detect_stop(thread_data) == 0)
		return (0);
	safe_printf(thread_data, thread_data->philo->id, "is sleeping\n");
	smart_usleep(get_timestamp(), thread_data->data->time_to_sleep,thread_data);
	return (1);
}
