/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:43:13 by msalim            #+#    #+#             */
/*   Updated: 2025/01/01 20:05:49 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#define NUM_PHILOSOPHERS 4
/*
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
*/
int main() {
    pthread_t threads[NUM_PHILOSOPHERS];
    t_philo philosophers[NUM_PHILOSOPHERS];
    pthread_mutex_t forks[NUM_PHILOSOPHERS];

    // Initialize mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Initialize philosophers and create threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosophers[i].id = i;
        philosophers[i].left_fork = &forks[i];
        philosophers[i].right_fork = &forks[(i + 1) % NUM_PHILOSOPHERS];

        // Create philosopher thread
        pthread_create(&threads[i], NULL, philo_lifecycle, &philosophers[i]);
    }

    // Wait for all threads to finish (this will never happen due to the infinite loop)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up mutexes (this will never happen due to infinite loop)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
