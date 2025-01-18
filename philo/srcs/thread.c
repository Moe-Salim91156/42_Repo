/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:10:16 by msalim            #+#    #+#             */
/*   Updated: 2025/01/18 14:57:53 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
int all_philos_have_eaten(t_thread_data *thread_data)
{
    int i;

    i = 0;
    while (i < thread_data->data->num_of_philos)
    {
      if (thread_data->philo[i].meals_eaten < thread_data->data->proper_meals)

        return 0;
    }

    return 1; // All philosophers have eaten the required number of meals
}

int man_im_dead(t_thread_data *thread_data)
{
    long time_since_last_meal;

    pthread_mutex_lock(&thread_data->philo->philo_mutex);
    time_since_last_meal = get_timestamp() - thread_data->philo->last_meal;
    pthread_mutex_unlock(&thread_data->philo->philo_mutex);

    if (time_since_last_meal >= thread_data->data->time_to_die)
    {
        pthread_mutex_lock(&thread_data->data->printf_mutex); // Lock for thread-safe access
        if (thread_data->data->stop_flag == 1) // Update stop_flag only once
        {
            thread_data->data->stop_flag = 0; // Stop the simulation
            printf("%ld philo %d died\n", get_timestamp(), thread_data->philo->id);
        }
        pthread_mutex_unlock(&thread_data->data->printf_mutex);
        return 0;
    }

    return 1; // Philosopher is alive
}

void	*philo_routine(void *args)
{
	t_thread_data	*thread_data;

	thread_data = (t_thread_data *)args;
	while (1)
	{ 
		if (!eating(thread_data) || !sleeping(thread_data) || (!thinking(thread_data)))
      break; 
    if (!man_im_dead(thread_data))
      break;
	}
	return (NULL);
}

int	create_thread(t_data *data, t_philo *philo)
{
	t_thread_data	*thread_data;
	int				i;

	i = 0;
	while (i < data->num_of_philos)
	{
		thread_data = init_thread_args(data, philo);
		if (!thread_data)
			return (-1);
        thread_data->philo = &philo[i];
		if (pthread_create(&philo[i].thread, NULL, philo_routine,
				(void *)thread_data) != 0)
		{
			free(thread_data);
			return (-1);
		}
		i++;
	}
	return (0);
}
