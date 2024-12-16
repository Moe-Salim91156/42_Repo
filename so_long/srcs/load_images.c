/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:09:56 by msalim            #+#    #+#             */
/*   Updated: 2024/12/15 17:44:51 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_images	*init_images_textures(void *mlx, t_game *game)
{
	t_images	*images;

	images = malloc(sizeof(t_images));
	if (!images)
		free_exit(game);
	images->height = 64;
	images->width = 64;
	images->wall = mlx_xpm_file_to_image(mlx, "./assets/wall64.xpm",
			&images->width, &images->height);
	images->floor = mlx_xpm_file_to_image(mlx, "./assets/floor.xpm",
			&images->width, &images->height);
	images->exit = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm",
			&images->width, &images->height);
	images->player = mlx_xpm_file_to_image(mlx, "./assets/player.xpm",
			&images->width, &images->height);
	images->collectible = mlx_xpm_file_to_image(mlx, "./assets/diamond.xpm",
			&images->width, &images->height);
	return (images);
}

static void	draw_tile(int i, int j, t_game *game)
{
	void	*image;

	if (game->map->array[i][j] == '1')
		image = game->image->wall;
	else if (game->map->array[i][j] == '0')
		image = game->image->floor;
	else if (game->map->array[i][j] == 'E')
		image = game->image->exit;
	else if (game->map->array[i][j] == 'P')
		image = game->image->floor;
	else if (game->map->array[i][j] == 'C')
		image = game->image->collectible;
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->window, image, j * 64, i * 64);
}

void	render_textures(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			draw_tile(i, j, game);
			j++;
		}
		i++;
	}
}

void	redraw_player(t_game *game, void *mlx, void *window)
{
	render_textures(game);
	mlx_put_image_to_window(mlx, window, game->image->player,
		game->player->x_pos * 64, game->player->y_pos * 64);
}
