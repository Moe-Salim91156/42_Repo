/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:10:16 by msalim            #+#    #+#             */
/*   Updated: 2025/01/26 13:38:54 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	all_philos_finished(t_philo *philos, int num_philos)
{
	int	i;
	int	all_done;

	i = 0;
	all_done = 1;
	while (i < num_philos)
	{
		if (philos->meals_eaten < philos->data->proper_meals)
		{
			all_done = 0;
			break ;
		}
		i++;
	}
	return (all_done);
}

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (detect_stop(philo))
	{
		if (philo->data->proper_meals != -1 && all_philos_finished(philo,
				philo->data->num_of_philos) == 1)
			break ;
		if (!man_im_dead(philo))
			break ;
		if (!eating(philo))
			break ;
		if (!sleeping(philo))
			break ;
		if (!thinking(philo))
			break ;
	}
	return (NULL);
}

int	create_thread(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, philo_routine,
				&philo[i]) != 0)
			return (-2);
		i++;
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
		{
			printf("join failed");
			return (-3);
		}
		i++;
	}
	return (0);
}
