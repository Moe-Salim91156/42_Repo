/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:04:08 by msalim            #+#    #+#             */
/*   Updated: 2024/09/11 14:08:48 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putstr(char *c);
int		ft_putnbr_hexa(unsigned long num, char *hex_digits);
int		ft_putnbr_pointer(unsigned long num, char *hex_digits);
int		ft_putnbr_un(unsigned int n);
#endif
