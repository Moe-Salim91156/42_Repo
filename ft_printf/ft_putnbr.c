/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:58:56 by msalim            #+#    #+#             */
/*   Updated: 2024/09/08 18:17:12 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	n1;
	int		length;

	n1 = n;
	length = 0;
	if (n1 < 0)
	{
		ft_putchar('-');
		n1 = -n1;
		length++;
	}
	if (n1 >= 10)
	{
		length += ft_putnbr(n1 / 10);
	}
	ft_putchar((n1 % 10) + '0');
	length++;
	return (length);
}
