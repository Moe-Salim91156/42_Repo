/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:02:47 by msalim            #+#    #+#             */
/*   Updated: 2025/01/21 19:36:53 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_mutexes_for_data(t_data *data)
{
	pthread_mutex_init(&data->printf_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	pthread_mutex_init(&data->data_mutex, NULL);
}

pthread_mutex_t	*init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->forks)
		return (NULL);
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (NULL);
		i++;
	}
	return (data->forks);
}

void	*init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->num_of_philos = atol(av[1]);
	data->time_to_die = atol(av[2]);
	data->time_to_eat = atol(av[3]);
	data->time_to_sleep = atol(av[4]);
	data->stop_flag = 1;
	if (ac == 6)
		data->proper_meals = atol(av[5]);
	else
		data->proper_meals = -1;
	init_mutexes_for_data(data);
	if (!init_forks(data))
		return (NULL);
	return (data);
}
void	*init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!philo)
		return (NULL);
	for (i = 0; i < data->num_of_philos; i++)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = &data->forks[i];
		philo[i].last_meal = get_timestamp();
		philo[i].right_fork = &data->forks[(i + 1) % data->num_of_philos];
		philo[i].meals_eaten = 0;
		philo[i].data = data;
		pthread_mutex_init(&philo[i].philo_mutex, NULL);
	}
	return (philo);
}

void	*init_thread_args(t_data *data, t_philo *philo)
{
	t_thread_data	*thread_data;

	thread_data = malloc(sizeof(t_thread_data));
	if (!thread_data)
		return (NULL);
	thread_data->data = data;
	thread_data->philo = philo;
	return (thread_data);
}
