/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:25:08 by msalim            #+#    #+#             */
/*   Updated: 2025/01/16 19:14:10 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_thread(t_data *data, t_philo *philo)
{
	// Join the threads to ensure they complete before the program exits
	for (int i = 0; i < data->num_of_philos; i++)
	{
		pthread_join(philo[i].thread, NULL);
		// Wait for each philosopher's thread to finish
	}
}
void	*init_structs(t_data **data, t_philo **philo, int ac, char **av)
{
	*data = init_data(ac, av);
	if (!*data)
		return (NULL);
	*philo = init_philo(*data);
	if (!*philo)
	{
		free(*data);
		return (NULL);
	}
	return ("success");
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	if (init_structs(&data, &philo, ac, av) == NULL)
		return (1);
	create_thread(data, philo);
	join_thread(data, philo);
	return (0);
}
