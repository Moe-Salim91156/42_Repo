/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:10:16 by msalim            #+#    #+#             */
/*   Updated: 2025/01/16 19:21:20 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(void *args)
{
	t_thread_data	*thread_data;

	thread_data = (t_thread_data *)args;
	while (1)
	{
		thinking(thread_data);
		eating(thread_data);
		sleeping(thread_data);
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
        thread_data->philo = &philo[i];  // Assign correct philosopher data to thread_data
		if (pthread_create(&philo[i].thread, NULL, philo_routine,
				(void *)thread_data) != 0)
		{
			perror("Error creating thread");
			free(thread_data);
			return (-1);
		}
		i++;
	}
	return (0);
}
