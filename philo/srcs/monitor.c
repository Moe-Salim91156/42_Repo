/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:32:05 by msalim            #+#    #+#             */
/*   Updated: 2025/01/20 19:28:33 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void *monitor(void *args)
{
    t_thread_data *thread_data = (t_thread_data *)args;

    while (detect_stop(thread_data)) {
        if (man_im_dead(thread_data) == 0) {
            pthread_mutex_lock(&thread_data->data->printf_mutex);
            pthread_mutex_lock(&thread_data->data->death_mutex);
            if (thread_data->data->stop_flag == 1) {
                thread_data->data->stop_flag = 0;
                printf("%ld philo %d died\n", get_timestamp(), thread_data->philo->id);
            }
            pthread_mutex_unlock(&thread_data->data->death_mutex);
            pthread_mutex_unlock(&thread_data->data->printf_mutex);
            break;
        }
        usleep(1000); // Sleep for a short while to avoid busy-waiting
    }

    return (NULL);
}
