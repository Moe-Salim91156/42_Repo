/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:23:50 by msalim            #+#    #+#             */
/*   Updated: 2025/01/16 19:10:29 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	debug_philos_init(t_data *data, t_philo *philos)
{
	if (!data || !philos)
	{
		printf("Error: Data or Philosophers are NULL\n");
		return ;
	}
	printf("Philosophers initialization:\n");
	for (int i = 0; i < data->num_of_philos; i++)
	{
		printf("Philosopher %d:\n", i);
		printf("ID: %d\n", philos[i].id);
		printf("Left Fork: %p\n", philos[i].left_fork);
		printf("Right Fork: %p\n", philos[i].right_fork);
		printf("Meals Eaten: %d\n", philos[i].meals_eaten);
		printf("Last Meal: %ld\n", philos[i].last_meal);
		// Add more fields as needed for debugging
	}
}
void	debug_mutex_init(t_data *data)
{
	if (!data)
	{
		printf("Error: Data struct is NULL\n");
		return ;
	}
	// Check if mutexes are initialized correctly
	if (pthread_mutex_trylock(&data->printf_mutex) == 0)
	{
		printf("Printf Mutex is working correctly.\n");
		pthread_mutex_unlock(&data->printf_mutex);
	}
	else
	{
		printf("Error: Printf Mutex initialization failed.\n");
	}
	if (pthread_mutex_trylock(&data->death_mutex) == 0)
	{
		printf("Death Mutex is working correctly.\n");
		pthread_mutex_unlock(&data->death_mutex);
	}
	else
	{
		printf("Error: Death Mutex initialization failed.\n");
	}
}
void	debug_forks_init(t_data *data)
{
	if (!data || !data->forks)
	{
		printf("Error: Forks are not initialized\n");
		return ;
	}
	printf("Forks initialization successful:\n");
	for (int i = 0; i < data->num_of_philos; i++)
	{
		printf("Fork %d initialized at memory address: %p\n", i,
			(void *)&data->forks[i]);
	}
}
#include <stdio.h>

void	debug_data_init(t_data *data)
{
	if (!data)
	{
		printf("Error: Data struct is NULL\n");
		return ;
	}
	printf("Data initialization successful:\n");
	printf("Number of Philosophers: %d\n", data->num_of_philos);
	printf("Time to Die: %ld\n", data->time_to_die);
	printf("Time to Eat: %ld\n", data->time_to_eat);
	printf("Time to Sleep: %ld\n", data->time_to_sleep);
	printf("Proper Meals: %d\n", data->proper_meals);
	// Add more fields as needed for debugging
}
