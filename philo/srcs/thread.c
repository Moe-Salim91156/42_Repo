/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:10:16 by msalim            #+#    #+#             */
/*   Updated: 2025/01/26 13:50:43 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	safe_printf(philo, philo->id, "has taken a fork\n");
	usleep(philo->data->time_to_die * 1000);
	pthread_mutex_unlock(philo->left_fork);
	safe_printf(philo, philo->id, "has died\n");
	philo->data->stop_flag = 0;
}

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
		if (philo->data->num_of_philos == 1)
		{
			handle_one_philo(philo);
			return (NULL);
		}
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
