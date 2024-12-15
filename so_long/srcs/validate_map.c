/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:46:07 by msalim            #+#    #+#             */
/*   Updated: 2024/12/15 18:08:00 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_rectangular(t_game *game)
{
	int	i;
	int	width;

	i = 1;
	while (i < game->map->height)
	{
		width = (int)ft_strlen(game->map->array[0]);
		if ((int)ft_strlen(game->map->array[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	validate_map_path(t_game *game)
{
	int				start_x;
	int				start_y;
	char			**cloned_map;
	int				collectible;
	t_flood_fill	*flood_data;

	start_x = game->player->x_pos;
	start_y = game->player->y_pos;
	collectible = game->total_collectibles;
	cloned_map = clone_map(game->map->array, game->map->height);
	if (!cloned_map)
	{
		return (0);
	}
	flood_data = init_flood(cloned_map, game->map, &collectible);
	if (!flood_data)
	{
		return (0);
	}
	flood_fill(start_x, start_y, flood_data);
	free(flood_data);
	free_2d_array(cloned_map, game->map->height);
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

int	validate_closed(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map->array[0][i] != '\n' && game->map->array[game->map->height
		- 1][j] != '\n')
	{
		if (game->map->array[0][i] != '1')
			return (0);
		if (game->map->array[game->map->height - 1][j] != '1')
			return (0);
		j++;
		i++;
	}
	i = 0;
	while (i < game->map->height)
	{
		if (game->map->array[i][0] != '1'
			|| game->map->array[i][game->map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!validate_map_path(game) || !validate_rectangular(game))
	{
		ft_putstr_fd("Error\n : invalid path : no exit or not rectangular\n",
			2);
		free_exit(game);
	}
	if (game->total_collectibles == 0)
	{
		ft_putstr_fd("Error\n : no collectibles\n", 2);
		free_exit(game);
	}
	if (validate_map_content(game) == 0 || game->player_pos_count != 1)
	{
		ft_putstr_fd("Error\n : invalid character/player_pos_count in map\n", 2);
		free_exit(game);
	}
	if (validate_closed(game) == 0)
	{
		ft_putstr_fd("Error\n : walls invalid\n", 2);
		free_exit(game);
	}
	return (1);
}
