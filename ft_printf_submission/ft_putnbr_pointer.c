/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:03:34 by msalim            #+#    #+#             */
/*   Updated: 2024/09/10 19:37:24 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_pointer(unsigned long num, char *hex_digits)
{
	char	buffer[17];
	int		i;
	int		count;

	if (num == 0)
		return (write(1, "(nil)", 5));
	count = 0;
	i = 0;
	count += ft_putstr("0x");
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
