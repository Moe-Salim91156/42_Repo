/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:09:56 by msalim            #+#    #+#             */
/*   Updated: 2024/12/08 19:57:27 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/so_long.h"

// read the map 2d array;
// check for the values (0,1,E,P,C);
// translate each value to their respective image;
//
void  draw_wall(t_map *map, void *mlx, void *window, void *img)
{
  //map height 5;
  //map width  13;
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
        mlx_put_image_to_window(mlx, window, img, j * 32 , i * 32);
        j++;
      }
      j++;
    }
    i++;
  }
}

