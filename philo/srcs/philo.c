/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:43:13 by msalim            #+#    #+#             */
/*   Updated: 2025/01/14 19:51:39 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
void debug_forks(t_data *data) {
    printf("Forks State:\n");
    for (int i = 0; i < data->num_of_philos; i++) {
        printf("  Fork %d: ", i);
        if (pthread_mutex_trylock(&data->forks[i]) == 0) {
            printf("Available\n");
            pthread_mutex_unlock(&data->forks[i]);
        } else {
            printf("In use\n");
        }
    }
}

void debug_philosophers(t_philo *philos, t_data *data) {
    for (int i = 0; i < data->num_of_philos; i++) {
        printf("Philosopher %d\n", philos[i].id);
        printf("  Left fork: %d\n", philos[i].left_fork);
        printf("  Right fork: %d\n", philos[i].right_fork);
        printf("  Last meal: %ld\n", philos[i].last_meal);  // Assuming last_meal is a timestamp
        printf("  Mutex: %p\n", (void *)&philos[i].philo_mutex);  // Print address of the philosopher mutex
    }
}
void debug_data(t_data *data) {
    printf("Data Structure State:\n");
    printf("  Number of philosophers: %d\n", data->num_of_philos);
    printf("  Time to die: %ld ms\n", data->time_to_die);
    printf("  Time to eat: %ld ms\n", data->time_to_eat);
    printf("  Time to sleep: %ld ms\n", data->time_to_sleep);
    printf("  Proper meals required: %d\n", data->proper_meals);

    // Print mutex addresses
    printf("  Printf mutex: %p\n", (void *)&data->printf_mutex);
    printf("  Die mutex: %p\n", (void *)&data->die_mutex);
}
void debug_threads(t_philo *philos, int num_of_philos) {
    printf("Thread Information:\n");
    for (int i = 0; i < num_of_philos; i++) {
        printf("  Philosopher %d Thread ID: %ld\n", philos[i].id, philos[i].thread);
    }
}

int main(int ac, char **av)
{
  int i;
  t_input_args args;
  t_philo *philos;
  t_data *data;

  i = 0;
  args.ac = ac;
  args.av = av;
  data = init_data(args);
  if (!data)
    return 1;
  philos = malloc(sizeof(t_philo) * data->num_of_philos);
  if (!philos)
    return 1;
  init_philo(philos,data);
      debug_data(data);  // Print overall data structure
    debug_philosophers(philos, data);  // Print philosophers' state
    debug_forks(data);  // Print forks' state
    debug_threads(philos, data->num_of_philos);
  while (i < data->num_of_philos)
  {
    pthread_join(philos[i].thread,NULL);
    i++;
  }
}
