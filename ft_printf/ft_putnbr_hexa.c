/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_lower.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:29:14 by msalim            #+#    #+#             */
/*   Updated: 2024/09/10 19:46:36 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long num, char *hex_digits)
{
	char	buffer[17];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (num == 0)
		return (write(1, "0", 1));
	while (num > 0)
	{
		buffer[i] = hex_digits[num % 16];
		num /= 16;
		i++;
	}
	buffer[i] = '\0';
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return (count);
}
