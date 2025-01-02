/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:23:44 by msalim            #+#    #+#             */
/*   Updated: 2025/01/02 19:44:55 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// using pthread_create, man pthread_create.
// creates a thread for each philo
// return 0 on sucess, otherwise any number
//
//	-> manual :        The pthread_create() function starts a new thread in the calling process.
//        The new thread starts execution by invoking start_routine();
//        arg is passed as the sole argument of start_routine().
//        Before returning,
//	a successful call to pthread_create() stores the ID of the new thread in
//        the buffer pointed to by thread;
//        this identifier is used to refer to the  thread  in  subsequent  calls  to
//        other pthreads functions.

//philo_life_cycle_function;
    //states of Philosophers
    //eating,thinking,sleeping
      //dying should be monitored
        //implemente dying state;
        //and detect it.
long long get_timestamp() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);  // Convert to milliseconds
}
void think(int id) 
{
    long long timestamp = get_timestamp();
    printf("%lld %d is thinking\n", timestamp, id);
    usleep(1000);  // Simulate thinking time
}
int  eating(int num_of_philos,pthread_mutex_t *forks, t_philo *philo)
{
  long long times = get_timestamp();
  if (pthread_mutex_lock(&forks[philo->id]) == 0)
  {
    printf("%lld %d has picked up right fork\n ", times, philo->id);
    if (pthread_mutex_lock(&forks[(philo->id + 1) % num_of_philos]) == 0)
    {
      printf("%lld %d has picked up left fork \n", times, philo->id);
      times= get_timestamp();
      printf("%lld %d is eating \n", times, philo->id);
      usleep(philo->sleep_time);
      pthread_mutex_unlock(&forks[philo->id]);
      pthread_mutex_unlock(&forks[(philo->id + 1) % num_of_philos]);
      printf("philo %d ate successfully\n", philo->id);
      return 1;
    }
    else
    {
      pthread_mutex_unlock(&forks[philo->id]);
      return 0;
    }
  }
  return (0);
}
void *philo_lifecycle(void *args)
{
    t_thread_args *thread_args = (t_thread_args *)args;
    pthread_mutex_t *forks = thread_args->forks;
    t_philo *philo = thread_args->philo;
    int num_of_philos = thread_args->num_of_philos;

    // Now, you can use the arguments as before
    int i = 0;
    long long times = get_timestamp();
    while (i < num_of_philos)
    {
        think(philo->id);  // Philosopher is thinking

        // Try to eat
        if (eating(num_of_philos, forks, philo) == 1) {
            // If eating was successful, philosopher goes to sleep
            printf("%lld %d is sleeping\n", times, philo->id);
            usleep(philo->sleep_time);  // Simulate sleeping time
        } else {
            // If eating wasn't successful, philosopher retries thinking
            think(philo->id);
        }
        i++;
    }

    return NULL;
}
void create_thread_philo(pthread_mutex_t *forks, t_philo *philo, int num_of_philos)
{
    pthread_t thread[num_of_philos];
    t_thread_args args[num_of_philos];

    for (int i = 0; i < num_of_philos; i++) {
        args[i].forks = forks;
        args[i].philo = &philo[i];
        args[i].num_of_philos = num_of_philos;

        // Create the thread and pass the argument structure
        if (pthread_create(&thread[i], NULL, philo_lifecycle, (void *)&args[i]) != 0) {
            perror("Failed to create thread");
        }
    }

    // Optionally, join the threads
    for (int i = 0; i < num_of_philos; i++) {
        pthread_join(thread[i], NULL);
    }
}
/*
void	create_thread_philo(int num_of_philos, t_philo *philo)
{
	int			i;
	pthread_t	*thread;

	// create a thread for each philo
	i = 0;
	thread = malloc(sizeof(pthread_t) * num_of_philos);
	if (!thread)
	{
		// free_something;
		exit(1);
	}
	while (i < num_of_philos)
	{
		pthread_create(&thread[i], NULL, philo_lifecycle, &philo[i);
		i++;
	}
	i = 0;
	while (i < num_of_philos)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}*/
