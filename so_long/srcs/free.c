/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:09:44 by msalim            #+#    #+#             */
/*   Updated: 2024/12/15 17:14:50 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_images(t_game *game)
{
	if (game->image)
	{
		if (game->image->wall)
			mlx_destroy_image(game->mlx, game->image->wall);
		if (game->image->floor)
			mlx_destroy_image(game->mlx, game->image->floor);
		if (game->image->exit)
			mlx_destroy_image(game->mlx, game->image->exit);
		if (game->image->player)
			mlx_destroy_image(game->mlx, game->image->player);
		if (game->image->collectible)
			mlx_destroy_image(game->mlx, game->image->collectible);
	}
}

void	free_map(t_game *game)
{
	int	i;

	if (game->map->array)
	{
		i = 0;
		while (game->map->array[i])
		{
			free(game->map->array[i]);
			i++;
		}
		free(game->map->array);
		free(game->map);
	}
}

void	free_2d_array(char **array, int height)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	if (array)
	{
		while (i < height)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	free_exit(t_game *game)
{
	if (game)
	{
		if (game->image)
		{
			free_images(game);
			free(game->image);
		}
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game->player)
			free(game->player);
		if (game->map)
			free_map(game);
		free(game);
	}
	exit(1);
}
