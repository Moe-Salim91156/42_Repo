/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_ft_strdup_basic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:30:20 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 18:57:39 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	test_strdup_basic(void)
{
	char	*dup;

	dup = ft_strdup("Hello");
	if (dup && ft_strcmp(dup, "Hello") == 0)
	{
		free(dup);
		return (0);
	}
	if (dup)
		free(dup);
	return (-1);
}
