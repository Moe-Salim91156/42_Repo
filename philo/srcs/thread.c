/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:23:44 by msalim            #+#    #+#             */
/*   Updated: 2025/01/01 20:03:54 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/philo.h"

//using pthread_create, man pthread_create.
//creates a thread for each philo
//return 0 on sucess, otherwise any number
//      -> manual :        The pthread_create() function starts a new thread in the calling process.
//        The new thread starts execution by invoking start_routine();
//        arg is passed as the sole argument of start_routine().
//        Before returning, a successful call to pthread_create() stores the ID of the new thread in 
//        the buffer pointed to by thread;
//        this identifier is used to refer to the  thread  in  subsequent  calls  to
//        other pthreads functions.
void *philo_lifecycle(void *arg) {
    t_philo *philo = (t_philo *)arg;
    
    while (1) {
        // THINKING
        printf("Philosopher %d is thinking.\n", philo->id);
        usleep(100);  // Random thinking time
        
        // PICK LEFT FORK
        printf("Philosopher %d is trying to pick up left fork.\n", philo->id);
        pthread_mutex_lock(philo->left_fork);
        printf("Philosopher %d picked up left fork.\n", philo->id);
        
        // PICK RIGHT FORK
        printf("Philosopher %d is trying to pick up right fork.\n", philo->id);
        pthread_mutex_lock(philo->right_fork);
        printf("Philosopher %d picked up right fork.\n", philo->id);
        
        // EATING
        printf("Philosopher %d is eating.\n", philo->id);
        usleep(1000000);  // Random eating time
        
        // PUT DOWN RIGHT FORK
        pthread_mutex_unlock(philo->right_fork);
        printf("Philosopher %d put down right fork.\n", philo->id);
        
        // PUT DOWN LEFT FORK
        pthread_mutex_unlock(philo->left_fork);
        printf("Philosopher %d put down left fork.\n", philo->id);
        
        // SLEEPING
        printf("Philosopher %d is sleeping.\n", philo->id);
        usleep(1000000);  // Random sleeping time
    }
    return NULL;
}
void  create_thread_philo(int num_of_philos, t_philo *philo)
{
  //create a thread for each philo
    int i;
    pthread_t *thread;

    i = 0;
    thread = malloc(sizeof(pthread_t) * num_of_philos);
    if (!thread)
    {
      //free_something;
      exit(1);
    }
    while (i < num_of_philos)
    {
      pthread_create(&thread[i], NULL, philo_lifecycle, &philo[i]);
      i++;
    }
  //assing the function start lifecycle for each philos
}
