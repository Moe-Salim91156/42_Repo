/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:11:27 by msalim            #+#    #+#             */
/*   Updated: 2025/07/29 16:45:54 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_executer(const char *format, va_list args, int i)
{
	int	count;

	count = 0;
	if (format[i] == 'd' || format[i] == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (format[i] == 'u')
		count = ft_putnbr_un(va_arg(args, unsigned int));
	else if (format[i] == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (format[i] == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (format[i] == '%')
		count = ft_putchar('%');
	else if (format[i] == 'p')
		count = ft_putnbr_pointer((va_arg(args, unsigned long)),
				"0123456789abcdef");
	else if (format[i] == 'x')
		count = ft_putnbr_hexa((unsigned long)(va_arg(args, unsigned int)),
				"0123456789abcdef");
	else if (format[i] == 'X')
		count = ft_putnbr_hexa((unsigned long)(va_arg(args, unsigned int)),
				"0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, format);
//TODO:FIX ABDHDHJ
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			length += ft_executer(format, args, i);
			i++;
		}
		else
		{
			write(1, &format[i++], 1);
			length++;
		}
	}
	va_end(args);
	return (length);
}
