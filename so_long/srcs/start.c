/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:51:30 by msalim            #+#    #+#             */
/*   Updated: 2024/12/11 18:57:43 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

t_game  *game_init()
{
  t_game  *game;

  game = malloc(sizeof(t_game));
  if (!game)
    return (NULL);
  game->map = init_map();
	store_map(game->map);
  game->player = init_player(game->map);
  count_collectibles(game);
  game->mlx = mlx_init();
	game->image = init_images_textures(game->mlx);
	game->window = mlx_new_window(game->mlx, game->map->width * 64, game->map->height * 64, "so_long");
  return (game);
}

int	handle_keypress(int keycode, t_game *game)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	if (keycode == 119 || keycode == 65362)
	{
		printf("Move Up\n");
		move_player(game, 0, -1);
	}
	if (keycode == 97 || keycode == 65361)
	{
		printf("Move Left\n");
		move_player(game, -1, 0);
	}
	if (keycode == 115 || keycode == 65364)
	{
		printf("Move Down\n");
		move_player(game, 0, 1);
	}
	if (keycode == 100 || keycode == 65363)
	{
		printf("Move Right\n");
		move_player(game, 1, 0);
	}
	return (0);
}

int	handle_close(t_game *game)
{
	mlx_string_put(game->mlx, game->window, 200, 250, 0xFFFFFF, "You Win!");
	// free game resrouces
	exit(0);
}

int	main(void)
{
  t_game  *game;

  game = game_init();
	render_textures(game);
	redraw_player(game, game->mlx, game->window);
	mlx_hook(game->window, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->window, 17, 0, handle_close, game);
	mlx_loop(game->mlx);
	return (0);
}
