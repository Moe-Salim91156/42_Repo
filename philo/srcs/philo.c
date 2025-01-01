/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:43:13 by msalim            #+#    #+#             */
/*   Updated: 2025/01/01 19:36:12 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int num_of_philos;
    if (argc != 2 || (num_of_philos = atoi(argv[1])) <= 1)
    {
        printf("Usage: %s [number_of_philosophers]\n", argv[0]);
        return (EXIT_FAILURE);
    }
    // Initialize resources
    t_philo *philo = init_philo(num_of_philos);
    pthread_mutex_t *forks = init_forks(num_of_philos);
    create_philos(num_of_philos, philo,forks);
    create_thread_philo(num_of_philos,philo);
     return (EXIT_SUCCESS);
}

