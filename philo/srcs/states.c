/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:39:19 by msalim            #+#    #+#             */
/*   Updated: 2025/01/23 20:15:14 by msalim           ###   ########.fr       */
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
  if (!man_im_dead(philo))
    return (0);
	if (philo->id % 2 == 0)
		eating1(philo);
	else
		eating2(philo);
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
