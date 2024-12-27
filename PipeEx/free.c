/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:26:41 by msalim            #+#    #+#             */
/*   Updated: 2024/11/27 16:31:44 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_strjoin(char *joined)
{
	if (joined)
		free(joined);
}

void	free_aall(char **splitted, char *cmd)
{
	int	i;

	i = 0;
	if (splitted)
	{
		while (splitted[i])
		{
			free(splitted[i]);
			i++;
		}
		free(splitted);
	}
	if (cmd)
		free(cmd);
}

void	free_all(char **split, char *joined)
{
	free_split(split);
	free_strjoin(joined);
}
