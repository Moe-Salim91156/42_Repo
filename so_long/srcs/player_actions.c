/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:49:24 by msalim            #+#    #+#             */
/*   Updated: 2024/12/10 19:27:57 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include  "../includes/so_long.h"

t_player  *init_player(t_map *map)
{
  t_player  *player;
  int i;
  int j;

  i = 0;
  j = 0;
player = malloc(sizeof(t_player));
    if (!player) {
        perror("error allocating memory for player");
        exit(1);
    }
  while (i < map->height)
  {
    j = 0;
    while (j < map->width)
    {
      if (map->array[i][j] == 'P')
      {
        player->x_pos = j;
        player->y_pos = i;
        return (player);
      }
      j++;
    }
    i++;
  }
  perror("error player init");
  return (NULL);
}
// moving player for now 

