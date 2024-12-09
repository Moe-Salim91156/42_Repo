/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:51:30 by msalim            #+#    #+#             */
/*   Updated: 2024/12/09 18:57:38 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

/*
 * map parser, get_next_line;
 * store the map into a 2D array;
 * morph the map into an image (images);
 * validate the map;
 * */
static t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		perror("failed to init map");
		exit(1);
	}
	map->width = 0;
	map->height = 0;
	map->array = NULL;
	return (map);
}

int	main(void)
{
	t_map	*map;
  void  *mlx;
  void  *window;
  void  *img;
  int width;
  int height;

	map = init_map();
	mlx = mlx_init();
	if (!mlx)
	{
		perror("MLX initialization failed");
		return (1);
	}
	window = mlx_new_window(mlx,835, 350 , "so_long");
	if (!window)
	{
		perror("Window creation failed");
		return (1);
	}
  img = mlx_xpm_file_to_image(mlx, "./assets/bg1.xpm", &width, &height);
  mlx_put_image_to_window(mlx,window,img,0,0);
  if(!img)
    perror("img nor found");
	store_map(map);
  t_images image = init_images_textures(mlx);
  draw_wall(map,mlx,window, image);
  mlx_loop(mlx);
	return (0);
}
