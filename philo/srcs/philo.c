/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:43:13 by msalim            #+#    #+#             */
/*   Updated: 2025/01/06 14:47:25 by msalim           ###   ########.fr       */
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
	t_input_args	args;

	num_of_philos = atoi(argv[1]);
	philo = malloc(sizeof(t_philo) * num_of_philos);
	if (!philo)
		return (0);
	args.ac = argc;
	args.av = argv;
	forks = init_forks(num_of_philos);
	create_philos(num_of_philos, philo, forks, args);
	create_thread_philo(forks, philo, num_of_philos);
	return (EXIT_SUCCESS);
}
