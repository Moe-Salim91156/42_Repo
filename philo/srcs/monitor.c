/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:32:05 by msalim            #+#    #+#             */
/*   Updated: 2025/01/22 20:04:28 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"
static int	check_died(t_data *data, t_philo *philo, int i)
{
    pthread_mutex_lock(&data->death_mutex);
    pthread_mutex_lock(&philo[i].philo_mutex);
    
    // Check if the philosopher has exceeded the time to die
    if (get_timestamp() - philo[i].last_meal >= data->time_to_die)
    {

      pthread_mutex_unlock(&philo[i].philo_mutex);
        pthread_mutex_lock(&data->printf_mutex);
        printf("%ld\t%d died\n", get_timestamp() - data->start_time, philo[i].id);
        pthread_mutex_unlock(&data->printf_mutex);
        
        // Update the stop flag to indicate that simulation should stop
        data->stop_flag = 0;
        pthread_mutex_unlock(&data->death_mutex);
        
        return (-1); // Philosopher is dead
    }
    
    pthread_mutex_unlock(&philo[i].philo_mutex);
    pthread_mutex_unlock(&data->death_mutex);
    usleep(1000); // Sleep for a short time before checking again
    return (0); // Philosopher is still alive
}

void  *monitor_routine(void *args)
{
  t_thread_data *monitor_data  = (t_thread_data *)args;
  int i;

    i = 0;
    while (i < monitor_data->data->num_of_philos)
    {
      if (check_died(monitor_data->data, monitor_data->philo,i) == EXIT_FAILURE)
        return (NULL);
      i++;
    }
  return (NULL);
}
