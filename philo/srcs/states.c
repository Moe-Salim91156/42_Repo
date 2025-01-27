/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:39:19 by msalim            #+#    #+#             */
/*   Updated: 2025/01/27 15:10:10 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	detect_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->stop_flag == 0)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (1);
}

int	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		lock_fork_even(philo);
		if (!eating1(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return (0);
		}
	}
	else
	{
		lock_fork_odd(philo);
		if (!eating2(philo))
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			return (0);
		}
	}
	return (1);
}

int	thinking(t_philo *philo)
{
	if (!man_im_dead(philo))
		return (0);
	safe_printf(philo, philo->id, "is thinking\n");
	return (1);
}

int	sleeping(t_philo *philo)
{
	if (!man_im_dead(philo))
		return (0);
	safe_printf(philo, philo->id, "is sleeping\n");
	smart_usleep(philo, get_timestamp(), philo->data->time_to_sleep);
	return (1);
}
