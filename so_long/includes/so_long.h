/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:07:15 by msalim            #+#    #+#             */
/*   Updated: 2024/12/12 18:34:36 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	int			has_exit_path;
	int			width;
	int			height;
	char		**array;
}				t_map;

typedef struct s_player
{
	int			x_pos;
	int			y_pos;
}				t_player;

typedef struct s_images
{
	void		*wall;
	int			height;
	int			width;
	void		*player;
	void		*floor;
	void		*collectible;
	void		*exit;
}				t_images;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	t_images	*image;
	int			total_collectibles;
	int			collectibles_left;
	void		*mlx;
	void		*window;
}				t_game;

int				open_map(void);
t_map			*store_map(t_map *map);
void			render_textures(t_game *game);
t_images		*init_images_textures(void *mlx);
int				validate_map(t_game *game);
void			redraw_player(t_game *game, void *mlx, void *window);
t_player		*init_player(t_map *map);
void			move_player(t_game *game, int dx, int dy);
t_map			*init_map(void);
void			count_collectibles(t_game *game);
#endif
