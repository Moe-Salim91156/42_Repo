/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_ft_bzero_zero_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:39:18 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 18:58:04 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	test_bzero_zero_len(void)
{
	char	buffer[5];

	buffer[0] = 't';
	buffer[1] = 'e';
	buffer[2] = 's';
	buffer[3] = 't';
	buffer[4] = '\0';
	ft_bzero(buffer, 0);
	if (ft_strcmp(buffer, "test") == 0)
		return (0);
	return (-1);
}
