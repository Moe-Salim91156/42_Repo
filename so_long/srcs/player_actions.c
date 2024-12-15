/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:49:24 by msalim            #+#    #+#             */
/*   Updated: 2024/12/15 18:07:16 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static void	get_player_position(t_game *game, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->array[i][j] == 'P')
			{
        game->player_pos_count++;
				player->x_pos = j;
				player->y_pos = i;
			}
			j++;
		}
		i++;
	}
}

t_player	*init_player(t_game *game)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		perror("error allocating memory for player");
		free_exit(game);
	}
	get_player_position(game, player);
	return (player);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x_pos + dx;
	new_y = game->player->y_pos + dy;
	if (game->map->array[new_y][new_x] != '1')
	{
		game->player->x_pos = new_x;
		game->player->y_pos = new_y;
		if (game->map->array[new_y][new_x] == 'C')
		{
			game->collectibles_left--;
			game->map->array[new_y][new_x] = '0';
		}
		if (game->map->array[new_y][new_x] == 'E')
		{
			if (game->collectibles_left == 0)
				free_exit(game);
		}
		game->moves++;
		redraw_player(game, game->mlx, game->window);
		ft_putnbr_fd(game->moves, 1);
		write(1, "\n", 1);
	}
}
