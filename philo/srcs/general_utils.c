/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:52:58 by msalim            #+#    #+#             */
/*   Updated: 2025/01/05 16:14:17 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/philo.h"
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putlong_fd(long n, int fd)
{
    if (n == -9223372036854775807L - 1) // Handle the edge case for LONG_MIN
    {
        write(fd, "-9223372036854775808", 20); // Output the minimum long value
        return;
    }
    if (n < 0)
    {
        ft_putchar_fd('-', fd); // Print negative sign
        n = -n; // Make the number positive for further processing
    }
    if (n >= 10)
    {
        ft_putlong_fd(n / 10, fd); // Recursively call for the quotient
    }
    ft_putchar_fd((n % 10) + '0', fd); // Print the last digit
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

