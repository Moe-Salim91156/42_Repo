/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:51:30 by msalim            #+#    #+#             */
/*   Updated: 2024/12/08 18:00:47 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

/*
 * map parser, get_next_line;
 * store the map into a 2D array;
 * morph the map into an image (images);
 * validate the map;
 * */

void	*mlx;
void	*window;
void	*img;
int width, height;

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

	map = init_map();
	mlx = mlx_init();
	if (!mlx)
	{
		perror("MLX initialization failed");
		return (1);
	}
	window = mlx_new_window(mlx, 1000, 700, "Image Example");
	if (!window)
	{
		perror("Window creation failed");
		return (1);
	}
	// Load an image
	img = mlx_xpm_file_to_image(mlx, "./assets/image.xpm", &width, &height);
	if (!img)
	{
		perror("Error loading image");
		return (1);
	}
	printf("MLX initialized: %p\n", mlx);
	printf("Window created: %p\n", window);
	printf("Image loaded: %p\n", img);
	store_map(map);
	return (0);
}
