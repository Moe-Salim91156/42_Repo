/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:58:50 by msalim            #+#    #+#             */
/*   Updated: 2025/01/05 18:52:54 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	has_philo_died(t_philo *philo)
{
	long	now;

	now = get_timestamp();
	if (now - philo->last_meal > philo->time_to_die)
	{
		pthread_mutex_lock(philo->printf_mutex);
		now = get_timestamp();
		printf("%ld %d has died\n", now, philo->id + 1);
		pthread_mutex_unlock(philo->printf_mutex);
		return (1);
	}
	return (0);
}

void	think(t_philo *philo)
{
	long	timestamp;

	timestamp = get_timestamp();
  pthread_mutex_lock(philo->printf_mutex);
	printf("%ld %d is thinking\n", timestamp, philo->id + 1);
  pthread_mutex_unlock(philo->printf_mutex);
  usleep(1000);
}

void	sleep_philo(t_philo *philo)
{
	long	timestamp;

	pthread_mutex_lock(philo->printf_mutex);
	timestamp = get_timestamp();
	printf("%ld %d is sleeping\n", timestamp, philo->id + 1);
	pthread_mutex_unlock(philo->printf_mutex);
	usleep(philo->sleep_time * 1000);
}

int	eating(int num_of_philos, pthread_mutex_t *forks, t_philo *philo)
{
	long	times;

	times = get_timestamp();
	if (philo->id % 2 == 0)
	{
		if (even_philo_logic(num_of_philos, forks, philo, times) == 0)
		{
			// free_here
			return (0);
		}
	}
	else
	{
		if (odd_philo_logic(num_of_philos, forks, philo, times) == 0)
		{
			// free_something here
			return (0);
		}
	}
	if (general_eating_logic(num_of_philos, forks, philo, times) == 1)
	{
		// free
		return (0);
	}
	return (1);
}
