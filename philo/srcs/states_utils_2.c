/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:32:05 by msalim            #+#    #+#             */
/*   Updated: 2025/01/26 13:14:23 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

long	ft_atol(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

void	lock_fork_even(t_philo *philo)
{
	if (detect_stop(philo))
	{
		pthread_mutex_lock(philo->left_fork);
		safe_printf(philo, philo->id, "has taken a fork\n");
	}
	if (detect_stop(philo))
	{
		pthread_mutex_lock(philo->right_fork);
		safe_printf(philo, philo->id, "has taken a fork\n");
	}
}

void	lock_fork_odd(t_philo *philo)
{
	if (detect_stop(philo))
	{
		pthread_mutex_lock(philo->right_fork);
		safe_printf(philo, philo->id, "has taken a fork\n");
	}
	if (detect_stop(philo))
	{
		pthread_mutex_lock(philo->left_fork);
		safe_printf(philo, philo->id, "has taken a fork\n");
	}
}
