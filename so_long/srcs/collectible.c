/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:42:44 by msalim            #+#    #+#             */
/*   Updated: 2024/12/11 19:03:25 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_collectibles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->total_collectibles = 0;
	game->collectibles_left = 0;
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->array[i][j] == 'C')
			{
				game->total_collectibles++;
				game->collectibles_left++;
			}
			j++;
		}
		i++;
	}
}
