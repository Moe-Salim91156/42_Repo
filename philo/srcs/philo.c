/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:25:08 by msalim            #+#    #+#             */
/*   Updated: 2025/01/16 16:46:06 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/philo.h"
void *init_structs(t_data **data, t_philo **philo, int ac, char **av)
{
    *data = init_data(ac, av); // Initialize t_data
    if (!*data)
        return (NULL); // Handle allocation failure for data

    *philo = init_philo(*data); // Initialize t_philo
    if (!*philo)
    {
        free(*data); // Free data if philo initialization fails
        return (NULL);
    }

    return ("success");
}

int main(int ac, char **av)
{
  t_data *data;
  t_philo *philo;

  if (init_structs(&data,&philo,ac,av) == NULL)
    return 1;
  debug_data_init(data);
  debug_philos_init(data,philo);
}
