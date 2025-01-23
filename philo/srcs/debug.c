/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:23:50 by msalim            #+#    #+#             */
/*   Updated: 2025/01/23 18:55:55 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
void debug_stop_flag(t_philo *philo)
{
      pthread_mutex_lock(&philo->philo_mutex);
        pthread_mutex_lock(&philo->data->death_mutex);
        pthread_mutex_lock(&philo->data->printf_mutex);
        printf("Philo %d stop_flag: %d\n", philo->id, philo->data->stop_flag);
        pthread_mutex_unlock(&philo->data->printf_mutex);
        pthread_mutex_unlock(&philo->data->death_mutex);
        pthread_mutex_unlock(&philo->philo_mutex);

}
void debug_last_meal(t_philo *philo)
{
        pthread_mutex_lock(&philo->philo_mutex);
        pthread_mutex_lock(&philo->data->printf_mutex);
        printf("Philo %d last_meal: %ld\n", philo->id, philo->last_meal);
        pthread_mutex_unlock(&philo->philo_mutex);
        pthread_mutex_unlock(&philo->data->printf_mutex);
}

void debug_all(t_philo *philo)
{
    debug_stop_flag(philo);
    debug_last_meal(philo);
}


