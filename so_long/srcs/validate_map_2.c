/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:11:05 by msalim            #+#    #+#             */
/*   Updated: 2024/12/14 18:24:11 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_rectangular(t_game *game)
{
	int	i;
	int	width;

	i = 1;
	while (i < game->map->height)
	{
		width = (int)ft_strlen(game->map->array[0]);
		if ((int)ft_strlen(game->map->array[i]) != width)
			return (0);
		i++;
	}
	return (1);
}
