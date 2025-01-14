/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:12:25 by msalim            #+#    #+#             */
/*   Updated: 2025/01/14 19:39:02 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(void *args)
{
	(void)args;
	return (NULL);
}
pthread_mutex_t	*init_forks(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->forks)
		return (NULL);
	return (data->forks);
}

t_data	*init_data(t_input_args args)
{
	int		i;
	t_data	*data;

	i = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->num_of_philos = atoi(args.av[1]);
	data->time_to_die = atol(args.av[2]);
	data->time_to_eat = atol(args.av[3]);
	data->time_to_sleep = atol(args.av[4]);
	if (args.ac == 6)
		data->proper_meals = atoi(args.av[5]);
	else
		data->proper_meals = -1;
	pthread_mutex_init(&data->printf_mutex, NULL);
	pthread_mutex_init(&data->die_mutex, NULL);
	if (!init_forks(data))
		return (NULL);
	while (i < data->num_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (data);
}

void	init_philo(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = i;
		philos[i].right_fork = (i + 1) % data->num_of_philos;
		philos[i].data = data;
		pthread_mutex_init(&philos[i].philo_mutex, NULL);
		philos[i].last_meal = get_timestamp();
		pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]);
		i++;
	}
}
