/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:12:25 by msalim            #+#    #+#             */
/*   Updated: 2025/01/05 18:44:19 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

pthread_mutex_t	*init_printf_mutex(void)
{
	pthread_mutex_t	*printf_mutex;

	printf_mutex = malloc(sizeof(pthread_mutex_t));
	if (!printf_mutex || pthread_mutex_init(printf_mutex, NULL) != 0)
	{
		perror("Failed to initialize printf mutex");
		exit(EXIT_FAILURE);
	}
	return (printf_mutex);
}

t_philo	*init_philo(int num_of_philos, t_input_args args)
{
	int		i;
	t_philo	*philo;
	long	start_time;

	start_time = get_timestamp();
	i = 0;
	philo = malloc(sizeof(t_philo) * num_of_philos);
	while (i < num_of_philos)
	{
		philo[i].id = i;
		philo[i].state = NULL;
		philo[i].left_fork = NULL;
		philo[i].right_fork = NULL;
		philo[i].last_meal = start_time;
		philo[i].sleep_time = atoi(args.av[4]);
		philo[i].eating_time = atoi(args.av[3]);
		philo[i].meals_eaten = 0;
		philo[i].proper_meals = 0;
		philo[i].time_to_die = atoi(args.av[2]);
		philo[i].printf_mutex = init_printf_mutex();
		i++;
	}
	return (philo);
}

pthread_mutex_t	*init_forks(int num_of_philos)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * num_of_philos);
	if (!forks)
	{
		// maybe free soemthing here;
		exit(1);
	}
	while (i < num_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

void	create_philos(int num_of_philos, t_philo *philo, pthread_mutex_t *forks,
		t_input_args args)
{
	int	i;
  pthread_mutex_t *value;
  value = init_printf_mutex();

	i = 0;
	while (i < num_of_philos)
	{
		philo[i].id = i;
		if (args.ac == 6)
			philo[i].proper_meals = atoi(args.av[5]);
		else
			philo[i].proper_meals = 1;
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % num_of_philos];
		philo[i].sleep_time = atoi(args.av[4]);
		philo[i].eating_time = atoi(args.av[3]);
		philo[i].time_to_die = atoi(args.av[2]);
		philo[i].meals_eaten = 0;
		philo[i].printf_mutex = value;
		i++;
	}
}
