/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:32:05 by msalim            #+#    #+#             */
/*   Updated: 2025/01/23 19:10:36 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	man_im_dead(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(&philo->data->data_mutex);
	last_meal = get_timestamp() - philo->last_meal;
	pthread_mutex_unlock(&philo->data->data_mutex);
	if (last_meal > philo->data->time_to_die)
	{
		safe_printf(philo, philo->id, "has died\n");
    kill_all_philo(philo);
		return (0);
	}
	return (1);
}
