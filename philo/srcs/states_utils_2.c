/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:32:05 by msalim            #+#    #+#             */
/*   Updated: 2025/01/27 15:13:18 by msalim           ###   ########.fr       */
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

int	ft_strcmp(const char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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

int	lock_fork_even(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	safe_printf(philo, philo->id, "has taken a fork\n");
	pthread_mutex_lock(philo->right_fork);
	safe_printf(philo, philo->id, "has taken a fork\n");
	return (1);
}

int	lock_fork_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	safe_printf(philo, philo->id, "has taken a fork\n");
	pthread_mutex_lock(philo->left_fork);
	safe_printf(philo, philo->id, "has taken a fork\n");
	return (1);
}
