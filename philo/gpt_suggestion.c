/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpt_suggestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:47:55 by msalim            #+#    #+#             */
/*   Updated: 2025/01/20 17:38:05 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * detect_stop - Checks if the simulation should stop.
 * @data: The shared data structure containing the stop flag.
 *
 * Returns 1 if the simulation should continue, 0 otherwise.
 */
int detect_stop(t_data *data) {
    int stop;

    pthread_mutex_lock(&data->stop_mutex);
    stop = data->stop_flag;
    pthread_mutex_unlock(&data->stop_mutex);

    return stop;
}

/**
 * set_stop_flag - Sets the stop flag for the simulation.
 * @data: The shared data structure containing the stop flag.
 * @value: The value to set (1 to continue, 0 to stop).
 */
void set_stop_flag(t_data *data, int value) {
    pthread_mutex_lock(&data->stop_mutex);
    data->stop_flag = value;
    pthread_mutex_unlock(&data->stop_mutex);
}

/**
 * smart_usleep - Sleeps in smaller chunks and checks stop_flag.
 * @duration: The total duration to sleep (in milliseconds).
 * @data: The shared data structure to check the stop_flag.
 */


/**
 * monitor_thread - Monitors philosophers to detect death or completion.
 * @arg: The shared data structure passed as a void pointer.
 *
 * Monitors if a philosopher dies or if all philosophers have eaten
 * their proper meals (if specified).
 */
void *monitor_thread(void *arg)
{
    t_data *data = (t_data *)arg;
    int all_full;

    while (detect_stop(data)) {
        all_full = 1;
        for (int i = 0; i < data->num_philos; i++)
        {
            pthread_mutex_lock(&data->philos[i].philo_mutex);
            if (get_timestamp() - data->philos[i].last_meal > data->time_to_die) 
            {
                pthread_mutex_lock(&data->printf_mutex);
                printf("%ld philo %d died\n", get_timestamp(), data->philos[i].id);
                pthread_mutex_unlock(&data->printf_mutex);
                set_stop_flag(data, 0);
                pthread_mutex_unlock(&data->philos[i].philo_mutex);
                return NULL;
            }
            if (data->proper_meals > 0 && data->philos[i].meals_eaten < data->proper_meals)
                all_full = 0;
            pthread_mutex_unlock(&data->philos[i].philo_mutex);
        }
        if (data->proper_meals > 0 && all_full)
        {
            pthread_mutex_lock(&data->printf_mutex);
            printf("All philosophers have eaten their proper meals.\n");
            pthread_mutex_unlock(&data->printf_mutex);
            set_stop_flag(data, 0);
            return NULL;
        }
        usleep(1000); // Check every 1 millisecond
    }
    return NULL;
}

/**
 * philosopher_thread - Executes the philosopher's lifecycle.
 * @arg: The philosopher's thread data passed as a void pointer.
 */
void *philosopher_thread(void *arg) {
    t_thread_data *thread_data = (t_thread_data *)arg;

    while (detect_stop(thread_data->data)) {
        if (!eating(thread_data))
            break;
        if (!sleeping(thread_data))
            break;
        if (!thinking(thread_data))
            break;
    }

    return NULL;
}
int	detect_stop(t_thread_data *thread_data)
{
	int	stop;

	pthread_mutex_lock(&thread_data->data->death_mutex);
	stop = thread_data->data->stop_flag;
	pthread_mutex_unlock(&thread_data->data->death_mutex);
	return (stop);
}

void	smart_usleep(long duration, t_thread_data *thread_data)
{
	int	slept;

	slept = 0;
	while (slept < duration && detect_stop(thread_data))
	{
		usleep(500); // Sleep in chunks of 500 microseconds
		slept += 0.5;
	}
}

void set_stop_flag(t_data *data, int value) {
    pthread_mutex_lock(&data->death_mutex);
    data->stop_flag = value;
    pthread_mutex_unlock(&data->death_mutex);
}
void *monitor_thread(void *arg)
{
    t_thread_data *thread_data = (t_thread_data *)arg;
    int all_full;

    while (detect_stop(thread_data)) {
        all_full = 1;
        for (int i = 0; i < thread_data->data->num_of_philos; i++)
        {
            pthread_mutex_lock(thread_data->philo->philo_mutex);
            if (get_timestamp() - thread_data->philo->last_meal > thread_data->data->time_to_die) 
            {
                pthread_mutex_lock(&thread_data->data->printf_mutex);
                printf("%ld philo %d died\n", get_timestamp(), thread_data->philo[i].id);
                pthread_mutex_unlock(&thread_data->data->printf_mutex);
                set_stop_flag(thread_data->data, 0);
                pthread_mutex_unlock(thread_data->philo->philo_mutex);
                return NULL;
            }
            if (thread_data->data->proper_meals > 0 && thread_data->philo[i].meals_eaten < thread_data->data->proper_meals)
                all_full = 0;
            pthread_mutex_unlock(thread_data->philo->philo_mutex);
        }
        if (thread_data->data->proper_meals > 0 && all_full)
        {
            pthread_mutex_lock(&thread_data->data->printf_mutex);
            printf("All philosophers have eaten their proper meals.\n");
            pthread_mutex_unlock(&thread_data->data->printf_mutex);
            set_stop_flag(thread_data->data, 0);
            return NULL;
        }
        usleep(1000); // Check every 1 millisecond
    }
    return NULL;
}


