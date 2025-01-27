/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:32:05 by msalim            #+#    #+#             */
/*   Updated: 2025/01/27 14:13:29 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	man_im_dead(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(&philo->philo_mutex);
	last_meal = get_timestamp() - philo->last_meal;
	pthread_mutex_lock(&philo->data->death_mutex);
	if (last_meal > philo->data->time_to_die)
	{
		if (philo->data->stop_flag == 1)
		{
			philo->data->stop_flag = 0;
			pthread_mutex_unlock(&philo->philo_mutex);
			pthread_mutex_unlock(&philo->data->death_mutex);
			safe_printf(philo, philo->id, "has died\n");
			return (0);
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
		pthread_mutex_unlock(&philo->philo_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_unlock(&philo->philo_mutex);
	return (1);
}
