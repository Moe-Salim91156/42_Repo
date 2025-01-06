/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:52:43 by msalim            #+#    #+#             */
/*   Updated: 2025/01/06 16:31:04 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_logs(long time, t_philo *philo, char *message)
{
	ft_putlong_fd(time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id + 1, 1);
	write(1, " ", 1);
	ft_putstr_fd(message, 1);
	usleep(1);
}

int	general_eating_logic(int num_of_philos, pthread_mutex_t *forks,
		t_philo *philo, long times)
{
	philo->last_meal = get_timestamp();
	if (pthread_mutex_lock(philo->printf_mutex) != 0)
		return (0);
	times = get_timestamp();
	printf("%ld %d is eating\n", times, philo->id + 1);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->printf_mutex);
	usleep(philo->eating_time * 1000);
	pthread_mutex_unlock(&forks[philo->id]);
	pthread_mutex_unlock(&forks[(philo->id + 1) % num_of_philos]);
	return (1);
}

int	odd_philo_logic(int num_of_philos, pthread_mutex_t *forks, t_philo *philo,
		long times)
{
	if (pthread_mutex_lock(&forks[(philo->id + 1) % num_of_philos]) != 0)
		return (0);
	pthread_mutex_lock(philo->printf_mutex);
	times = get_timestamp();
	printf("%ld %d has picked up right fork\n", times, philo->id + 1);
	pthread_mutex_unlock(philo->printf_mutex);
	if (pthread_mutex_lock(&forks[philo->id]) != 0)
	{
		pthread_mutex_unlock(&forks[(philo->id + 1) % num_of_philos]);
		return (0);
	}
	pthread_mutex_lock(philo->printf_mutex);
	times = get_timestamp();
	printf("%ld %d has picked up left fork\n", times, philo->id + 1);
	pthread_mutex_unlock(philo->printf_mutex);
	return (1);
}
int	even_philo_logic(int num_of_philos, pthread_mutex_t *forks, t_philo *philo,
		long times)
{
	if (pthread_mutex_lock(&forks[philo->id]) != 0)
		return (0);
	pthread_mutex_lock(philo->printf_mutex);
	times = get_timestamp();
	printf("%ld %d has picked up left fork\n", times, philo->id + 1);
	pthread_mutex_unlock(philo->printf_mutex);
	if (pthread_mutex_lock(&forks[(philo->id + 1) % num_of_philos]) != 0)
	{
		pthread_mutex_unlock(&forks[philo->id]);
		return (0);
	}
	pthread_mutex_lock(philo->printf_mutex);
	times = get_timestamp();
	printf("%ld %d has picked up right fork\n", times, philo->id + 1);
	pthread_mutex_unlock(philo->printf_mutex);
	return (1);
}
