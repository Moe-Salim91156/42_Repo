/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:51:30 by msalim            #+#    #+#             */
/*   Updated: 2024/12/10 19:45:18 by msalim           ###   ########.fr       */
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

void redraw_player(t_game *game, void *mlx, void *window)
{
    draw_wall(game);  // Assuming this draws the whole map including walls
    mlx_put_image_to_window(mlx, window, game->image->player, game->player->x_pos * 64, game->player->y_pos * 64);
}


void move_player(t_game *game,int dx, int dy)
{
    int new_x = game->player->x_pos + dx;
    int new_y = game->player->y_pos + dy;
    if (game->map->array[new_y][new_x] != '1') 
    {
        game->player->x_pos = new_x;
        game->player->y_pos = new_y;
    if (game->map->array[new_y][new_x] == 'C') 
    {
            game->collectibles_left--;
            printf("game collectible decreased");
    }
    if (game->map->array[new_y][new_x] == 'E') 
    {
            printf("game exit reached");
    }

        redraw_player(game,game->mlx, game->window);
    }
}

int handle_keypress(int keycode, t_game *game) {
    printf("Keycode: %d\n", keycode);  // Debugging: print keycode

    if (keycode == 65307) {  // ESC key
        exit(0);  // Exit the game
    }

    // Debugging movement keys (W, A, S, D, arrow keys)
    if (keycode == 119 || keycode == 65362) {  // W or Up Arrow
        printf("Move Up\n");
        move_player(game, 0, -1);
    }
    if (keycode == 97 || keycode == 65361) {  // A or Left Arrow
        printf("Move Left\n");
        move_player(game,  -1, 0);
    }
    if (keycode == 115 || keycode == 65364) {  // S or Down Arrow
        printf("Move Down\n");
        move_player(game,  0, 1);
    }
    if (keycode == 100 || keycode == 65363) {  // D or Right Arrow
        printf("Move Right\n");
        move_player(game,  1, 0);
    }

    return 0;
}
int main(void) {
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!game)
      perror("game error load");
    game->map = init_map();
    store_map(game->map);
    game->player = init_player(game->map);
    game->collectibles_left = 1;
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, 800, 500, "so_long");
    game->image = init_images_textures(game->mlx);
    draw_wall(game);
    mlx_hook(game->window, 2, 1L << 0, handle_keypress, game); // Pass the game struct
    mlx_loop(game->mlx);

    return (0);
}

