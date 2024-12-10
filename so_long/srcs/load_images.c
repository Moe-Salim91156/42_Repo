/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:09:56 by msalim            #+#    #+#             */
/*   Updated: 2024/12/10 19:40:12 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/so_long.h"

// read the map 2d array;
// check for the values (0,1,E,P,C);
// translate each value to their respective image;
//
t_images  *init_images_textures(void *mlx)
{
  t_images  *images;

  images = malloc(sizeof(t_images));
  int height = 64;
  int width = 64;
  images->wall = mlx_xpm_file_to_image(mlx, "./assets/wall64.xpm", &width, &height);
  images->floor = mlx_xpm_file_to_image(mlx, "./assets/floor.xpm", &width,&height);
  images->exit = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", &width, &height);
  images->player = mlx_xpm_file_to_image(mlx, "./assets/player.xpm", &width, &height);
  images->collectible = mlx_xpm_file_to_image(mlx,"./assets/diamond.xpm",&width, &height);
  return (images);
}

void  draw_wall(t_game *game)
{
  int i;
  int j;

  j = 0;
  i = 0;
  while (i < game->map->height)
  {
    j = 0;
    while (j < game->map->width)
    {
      if (game->map->array[i][j] == '1')
      {
        mlx_put_image_to_window(game->mlx, game->window, game->image->wall, j * 64 , i * 64);
        j++;
      }
      else if (game->map->array[i][j] == '0')
      {
        mlx_put_image_to_window(game->mlx, game->window, game->image->floor, j * 64 , i * 64);
        j++;
      }
      else if (game->map->array[i][j] == 'C')
      {
        mlx_put_image_to_window(game->mlx,game->window,game->image->collectible, j * 64, i * 64);
        j++;
      }
      else if (game->map->array[i][j] == 'E')
      {
        mlx_put_image_to_window(game->mlx,game->window,game->image->exit, j * 64, i * 64);
        j++;
      }
      else if (game->map->array[i][j] == 'P')
      {
        mlx_put_image_to_window(game->mlx,game->window,game->image->floor, j * 64, i * 64);
        j++;
      }
      else
        j++;
    }
    i++;
  }
}

