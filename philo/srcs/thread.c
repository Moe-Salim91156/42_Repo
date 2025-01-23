/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:10:16 by msalim            #+#    #+#             */
/*   Updated: 2025/01/23 19:16:27 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void kill_all_philo(t_philo *philo)
{
    int i = 0;
    pthread_mutex_lock(&philo->data->data_mutex); // Lock the global mutex if needed
    while (i < philo->data->num_of_philos)
    {
      pthread_mutex_lock(&philo->data->death_mutex);
        if (philo->data->stop_flag == 1)
        {
            philo->data->stop_flag = 0;
        }
        pthread_mutex_unlock(&philo->data->death_mutex);
        i++;
    }
    pthread_mutex_unlock(&philo->data->data_mutex); // Unlock the global mutex
    usleep(100);  // Sleep to avoid excessive CPU usage
}

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (detect_stop(philo))
	{
		if (!man_im_dead(philo))
      break;
		if (!eating(philo))
			break ;
		if (!sleeping(philo))
			break ;
		if (!thinking(philo))
			break ;
	}
	return (NULL);
}

int	create_thread(t_data *data, t_philo *philo)
{
	int			i;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * data->num_of_philos);
	if (!threads)
		return (-1);
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&threads[i], NULL, philo_routine, &philo[i]) != 0)
			return (-2);
		i++;
	}
	for (int i = 0; i < data->num_of_philos; i++)
		pthread_join(threads[i], NULL);
	return (0);
}
