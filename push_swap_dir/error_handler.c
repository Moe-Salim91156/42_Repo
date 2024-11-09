/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:49:37 by msalim            #+#    #+#             */
/*   Updated: 2024/11/09 18:58:46 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// join and split >> (handle stupid input) >> DONE
// check if digit >>  DONE
// check if there is duplicates >> DONE
// check if its pass MAX_INT

static int	check_duplicate(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_atoi(numbers[i]) == ft_atoi(numbers[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_digit_only(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char **numbers)
{
	int		i;
	long	number;

	i = 0;
	while (numbers[i])
	{
		number = ft_atol(numbers[i]);
		if (number >= 2147483647 || number <= -2147483648)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (!is_digit_only(numbers[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		else if (!check_duplicate(numbers))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	calculate_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;
	int	sep_len;

	sep_len = ft_strlen(sep);
	total_len = 0;
	i = 0;
	while (i < size)
		total_len += ft_strlen(strs[i++]);
	total_len += (size - 2) * sep_len + 1;
	return (total_len);
}

char	*ft_strjoin_new(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;

	s = malloc(calculate_total_len(size, strs, sep) * sizeof(char));
	if (!s)
		return (NULL);
	i = 1;
	c = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			s[c++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			s[c++] = sep[j++];
		i++;
	}
	s[c] = '\0';
	return (s);
}
