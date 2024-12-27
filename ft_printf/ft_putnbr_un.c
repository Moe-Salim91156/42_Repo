/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:16:07 by msalim            #+#    #+#             */
/*   Updated: 2024/09/08 19:15:11 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned int n)
{
	int	length;

	length = 0;
	if (n >= 10)
	{
		length += ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
	length++;
	return (length);
}
