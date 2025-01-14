/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:58:50 by msalim            #+#    #+#             */
/*   Updated: 2025/01/13 13:54:48 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	proper_meals_reached(t_philo *philo, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		if (philo->proper_meals && philo->meals_eaten == philo->proper_meals)
		{
			printf("%ld Philo has eaten its proper meals %ld\n",
				philo->proper_meals, philo->meals_eaten);
			return (1);
		}
		i++;
	}
	return (0);
}

int	has_philo_died(t_philo *philo)
{
	long	now;

	now = get_timestamp();
	if (now - philo->last_meal >= philo->time_to_die)
	{
		pthread_mutex_lock(philo->printf_mutex);
		now = get_timestamp();
		printf("%ld %d has died\n", now, philo->id + 1);
		pthread_mutex_unlock(philo->printf_mutex);
		return (1);
	}
	return (0);
}
// 4 600 100 100
int	think(t_philo *philo)
{
	long	timestamp;

	timestamp = get_timestamp();
  if (has_philo_died(philo))
    return(1);
	pthread_mutex_lock(philo->printf_mutex);
	printf("%ld %d is thinking\n", timestamp, philo->id + 1);
	pthread_mutex_unlock(philo->printf_mutex);
	usleep(1000);
  return (0);
}

int sleep_philo(t_philo *philo)
{
	long	timestamp;

  if (has_philo_died(philo))
    return (1);
	pthread_mutex_lock(philo->printf_mutex);
	timestamp = get_timestamp();
	printf("%ld %d is sleeping\n", timestamp, philo->id + 1);
	pthread_mutex_unlock(philo->printf_mutex);
	usleep(philo->sleep_time * 1000);
  return (0);
}

int	eating(int num_of_philos, pthread_mutex_t *forks, t_philo *philo)
{
	long	times;

	times = get_timestamp();
  if (has_philo_died(philo))
    return (1);
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
	if (general_eating_logic(num_of_philos, forks, philo, times) == 0)
	{
		// free
		return (0);
	}
  //printf("last meal in eating %ld\n",philo->last_meal);
  philo->last_meal = get_timestamp();
  philo->meals_eaten++;
	return (0);
}
