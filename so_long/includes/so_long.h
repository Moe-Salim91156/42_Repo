/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:07:15 by msalim            #+#    #+#             */
/*   Updated: 2024/12/09 17:47:05 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	int		width;
	int		height;
	char	**array;
}			t_map;

typedef struct s_images
{
  void  *wall;
  void  *player;
  void  *floor;
  void  *collectible;
  void  *exit;
} t_images;

int		open_map();
t_map  *store_map(t_map *map);
void  draw_wall(t_map *map, void *mlx, void *window, t_images image);
t_images  init_images_textures(void *mlx);
#endif
