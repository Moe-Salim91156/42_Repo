/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:09:56 by msalim            #+#    #+#             */
/*   Updated: 2024/12/09 18:57:06 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/so_long.h"

// read the map 2d array;
// check for the values (0,1,E,P,C);
// translate each value to their respective image;
//
t_images  init_images_textures(void *mlx)
{
  t_images  images;

  int height = 64;
  int width = 64;
  images.wall = mlx_xpm_file_to_image(mlx, "./assets/wall64.xpm", &width, &height);
  images.floor = mlx_xpm_file_to_image(mlx, "./assets/floor64.xpm", &width,&height);
  images.exit = NULL;
  images.player = NULL;
  images.collectible = mlx_xpm_file_to_image(mlx,"./assets/coin32.xpm",&width, &height);
  return (images);
}

void  draw_wall(t_map *map, void *mlx, void *window, t_images image)
{
  int i;
  int j;

  j = 0;
  i = 0;
  while (i < map->height)
  {
    j = 0;
    while (j < map->width)
    {
      if (map->array[i][j] == '1')
      {
        mlx_put_image_to_window(mlx, window, image.wall, j * 64 , i * 64);
        j++;
      }
      else if (map->array[i][j] == '0')
      {
        mlx_put_image_to_window(mlx, window, image.floor, j * 64 , i * 64);
        j++;
      }
      else if (map->array[i][j] == 'C')
      {
        mlx_put_image_to_window(mlx,window,image.collectible, j * 64, i * 64);
        j++;
      }
      else
        j++;
    }
    i++;
  }
}

