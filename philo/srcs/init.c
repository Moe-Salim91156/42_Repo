/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:02:47 by msalim            #+#    #+#             */
/*   Updated: 2025/01/27 15:08:33 by msalim           ###   ########.fr       */
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
	data->num_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	data->start_time = get_timestamp();
	data->stop_flag = 1;
	if (ac == 6)
		data->proper_meals = ft_atol(av[5]);
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

	i = 0;
	philo = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!philo)
		return (NULL);
	while (i < data->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = &data->forks[i];
		philo[i].last_meal = get_timestamp();
		philo[i].right_fork = &data->forks[(i + 1) % data->num_of_philos];
		philo[i].meals_eaten = 0;
		philo[i].data = data;
		pthread_mutex_init(&philo[i].philo_mutex, NULL);
		i++;
	}
	return (philo);
}
