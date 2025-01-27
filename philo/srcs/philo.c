/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:25:08 by msalim            #+#    #+#             */
/*   Updated: 2025/01/27 15:08:14 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	if (create_thread(data, philo) != 0)
	{
		cleanup_mutexes(data);
		cleanup_philos(philo, data);
		free(data);
		return (1);
	}
	else
		cleanup(data, philo);
	return (0);
}
