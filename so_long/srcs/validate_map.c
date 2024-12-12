/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:46:07 by msalim            #+#    #+#             */
/*   Updated: 2024/12/12 19:09:21 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	flood_fill(char **map, int x, int y, t_map *original_map, int *collectibles)
{
	if (x < 0 || y < 0 || x >= original_map->width || y >= original_map->height)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'C')
		(*collectibles)--;
	if (map[y][x] == 'E')
		original_map->has_exit_path = 1;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, original_map, collectibles);
	flood_fill(map, x - 1, y, original_map, collectibles);
	flood_fill(map, x, y + 1, original_map, collectibles);
	flood_fill(map, x, y - 1, original_map, collectibles);
	return (0);
}

int	validate_map_path(t_game *game, int start_x, int start_y)
{
	char	**cloned_map;
	int		collectible;
	int		i;

	collectible = game->total_collectibles;
	game->map->has_exit_path = 0;
	cloned_map = malloc(sizeof(char *) * game->map->height);
	i = 0;
	while (i < game->map->height)
	{
		cloned_map[i] = ft_strdup(game->map->array[i]);
		i++;
	}
	flood_fill(cloned_map, start_x, start_y, game->map, &collectible);
	// free_cloned map
	if (collectible == 0 && game->map->has_exit_path)
		return (1);
	return (0);
}

int	validate_map_content(t_game *game)
{
	int		i;
	int		j;
	char	map_char;

	i = 0;
	j = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			map_char = game->map->array[i][j];
			if (map_char != '1' && map_char != '0' && map_char != 'P'
				&& map_char != 'C' && map_char != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int validate_rectangular(t_game *game)
{
  if (game->map->array[0])
  {
    printf("has walls correctly ");
    return (1);
  }
  return (0);
}
int	validate_map(t_game *game)
{
	int	start_x;
	int	start_y;

	start_x = game->player->x_pos;
	start_y = game->player->y_pos;
	if (!validate_map_path(game, start_x, start_y))
	{
		ft_putstr_fd("Error: No valid path to exit\n", 2);
		// free
		exit(1);
	}
	if (game->total_collectibles == 0)
	{
		ft_putstr_fd("no collectibles", 2);
		// free
		exit(1);
	}
	if (validate_map_content(game) == 0) // invalid char
	{
		ft_putstr_fd("invalid character in map\n", 2);
		// free
		exit(1);
	}
  if (validate_rectangular(game) == 0)
  {
    ft_putstr_fd("walls invalid",2);
    //free;
    exit(1);
  }
	return (1);
}
