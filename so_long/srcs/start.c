/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:51:30 by msalim            #+#    #+#             */
/*   Updated: 2024/12/15 18:26:38 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

t_game	*game_init(char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = init_map(game);
	game->moves = 0;
	game->player_pos_count = 0;
	store_map(game, av);
	game->player = init_player(game);
	count_collectibles(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		free_exit(game);
	game->image = init_images_textures(game->mlx, game);
	game->window = mlx_new_window(game->mlx, game->map->width * 64,
			game->map->height * 64, "so_long");
	if (!game->window || !validate_map(game))
		free_exit(game);
	return (game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_exit(game);
	if (keycode == 119 || keycode == 65362)
	{
		move_player(game, 0, -1);
	}
	if (keycode == 97 || keycode == 65361)
	{
		move_player(game, -1, 0);
	}
	if (keycode == 115 || keycode == 65364)
	{
		move_player(game, 0, 1);
	}
	if (keycode == 100 || keycode == 65363)
	{
		move_player(game, 1, 0);
	}
	return (0);
}

int	handle_close(t_game *game)
{
	free_exit(game);
	exit(1);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac == 2)
	{
		game = game_init(av);
		render_textures(game);
		redraw_player(game, game->mlx, game->window);
		mlx_hook(game->window, 2, 1L << 0, handle_keypress, game);
		mlx_hook(game->window, 17, 0, handle_close, game);
		mlx_loop(game->mlx);
	}
	return (0);
}
