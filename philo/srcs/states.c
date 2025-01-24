/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:39:19 by msalim            #+#    #+#             */
/*   Updated: 2025/01/24 19:38:38 by msalim           ###   ########.fr       */
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
		if (detect_stop(philo))
		{
			pthread_mutex_lock(philo->left_fork);
			safe_printf(philo, philo->id, "has taken a fork\n");
			pthread_mutex_lock(philo->right_fork);
			safe_printf(philo, philo->id, "has taken a fork\n");
		}
		if (!eating1(philo))
			return (0);
	}
	else
	{
		if (detect_stop(philo))
		{
			pthread_mutex_lock(philo->right_fork);
			safe_printf(philo, philo->id, "has taken a fork\n");
			pthread_mutex_lock(philo->left_fork);
			safe_printf(philo, philo->id, "has taken a fork\n");
		}
		if (!eating2(philo))
			return (0);
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
	if (!man_im_dead(philo))
		return (0);
	return (1);
}
