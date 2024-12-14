/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:34:23 by msalim            #+#    #+#             */
/*   Updated: 2024/12/14 19:52:41 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*init_map(t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		perror("failed to init map");
		free_exit(game);
	}
	map->width = 0;
	map->height = 0;
	map->array = NULL;
	return (map);
}

int	map_lines_count(int map_fd)
{
	int		line_count;
	char	*line;

	line_count = 0;
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		line_count++;
		free(line);
	}
	return (line_count);
}

int	open_map(void)
{
	int	map_fd;

	map_fd = open("./assets/map1.ber", O_RDONLY);
	if (map_fd < 0)
	{
		perror("error opening map file");
		exit(1);
	}
	return (map_fd);
}
t_map	*store_map(t_game *game)
{
	int	line_count;
	int	i;
	int	map_fd;

	i = 0;
	map_fd = open_map();
	line_count = map_lines_count(map_fd);
	game->map->array = malloc(sizeof(char *) * (line_count + 1));
	if (!game->map->array)
		free_exit(game);
	close(map_fd);
	map_fd = open_map();
	while (i < line_count)
	{
		game->map->array[i] = get_next_line(map_fd);
		if (i == 0)
			game->map->width = ft_strlen(game->map->array[i]) - 1;
		i++;
	}
	game->map->height = line_count;
	game->map->array[i] = NULL;
	close(map_fd);
	return (game->map);
}
/*
  printf("height of map  : %d\n" , map->height);
  printf("width of map  : %d\n" , map->width);
  for (int e = 0; e < line_count; e++)
		printf(" array %s\n" , map->array[e]);
*/
