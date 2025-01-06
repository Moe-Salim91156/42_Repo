/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:12:25 by msalim            #+#    #+#             */
/*   Updated: 2025/01/06 18:07:28 by msalim           ###   ########.fr       */
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
pthread_mutex_t *init_end_mutex(void)
{
	pthread_mutex_t	*end_mutex;

	end_mutex = malloc(sizeof(pthread_mutex_t));
	if (!end_mutex || pthread_mutex_init(end_mutex, NULL) != 0)
	{
		perror("Failed to initialize printf mutex");
		exit(EXIT_FAILURE);
	}
	return (end_mutex);
}

t_simulation *init_simulation(void)
{
    t_simulation *simulation = malloc(sizeof(t_simulation));
    if (!simulation)
        return (NULL);
    simulation->simulation_stop_flag = 0;
    simulation->sim_end_mutex = malloc(sizeof(pthread_mutex_t));
    if (!simulation->sim_end_mutex)
      printf("as;ldkfjas;dlkfjas;f");
    // Initialize mutex to control simulation end state
    if (pthread_mutex_init(simulation->sim_end_mutex, NULL) != 0)
    {
        free(simulation);
        return (NULL);
    }
    
    return (simulation);
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
	int				i;
	pthread_mutex_t	*value;
	pthread_mutex_t	*value2;

	value = init_printf_mutex();
  value2 = init_end_mutex();
	i = 0;
	while (i < num_of_philos)
	{
		philo[i].id = i;
		if (args.ac == 6)
			philo[i].proper_meals = atoi(args.av[5]);
		else
			philo[i].proper_meals = 0;
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % num_of_philos];
		philo[i].sleep_time = atoi(args.av[4]);
		philo[i].eating_time = atoi(args.av[3]);
		philo[i].time_to_die = atoi(args.av[2]);
		philo[i].meals_eaten = 0;
		philo[i].printf_mutex = value;
    philo[i].end_mutex = value2;
    philo[i].last_meal = get_timestamp();
    philo[i].stop_flag = 1;
		i++;
	}
}
