/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:40:04 by msalim            #+#    #+#             */
/*   Updated: 2024/12/15 13:49:28 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_flood_fill	*init_flood(char **map, t_map *original_map, int *collectibles)
{
	t_flood_fill	*flood_data;

	flood_data = malloc(sizeof(t_flood_fill));
	if (!flood_data)
		return (NULL);
	flood_data->map = map;
	flood_data->original_map = original_map;
	flood_data->collectible = collectibles;
	return (flood_data);
}

char	**clone_map(char **original_map, int height)
{
	char	**cloned_map;
	int		i;

	cloned_map = malloc(sizeof(char *) * height);
	if (!cloned_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		cloned_map[i] = ft_strdup(original_map[i]);
		if (!cloned_map[i])
		{
			free_2d_array(cloned_map, i);
			return (NULL);
		}
		i++;
	}
	return (cloned_map);
}

int	flood_fill(int x, int y, t_flood_fill *data)
{
	if (x < 0 || y < 0 || x >= data->original_map->width
		|| y >= data->original_map->height)
		return (0);
	if (data->map[y][x] == '1' || data->map[y][x] == 'V')
		return (0);
	if (data->map[y][x] == 'C')
		(*data->collectible)--;
	if (data->map[y][x] == 'E')
		data->original_map->has_exit_path = 1;
	data->map[y][x] = 'V';
	flood_fill(x + 1, y, data);
	flood_fill(x - 1, y, data);
	flood_fill(x, y + 1, data);
	flood_fill(x, y - 1, data);
	return (0);
}
