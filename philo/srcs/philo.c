/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:43:13 by msalim            #+#    #+#             */
/*   Updated: 2025/01/02 19:42:13 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_PHILOSOPHERS 4

int	main(int argc, char **argv)
{
	int				num_of_philos;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	if (argc != 5 || (num_of_philos = atoi(argv[1])) <= 1)
	{
		printf("Usage: %s [number_of_philosophers]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	// Initialize resources
	philo = init_philo(num_of_philos,argv);
	forks = init_forks(num_of_philos);
	create_philos(num_of_philos, philo, forks);
	create_thread_philo(forks, philo, num_of_philos);
	return (EXIT_SUCCESS);
}
