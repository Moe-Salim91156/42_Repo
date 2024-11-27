/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:58:04 by msalim            #+#    #+#             */
/*   Updated: 2024/11/27 14:15:45 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// cat the "cmd" to each word (path);
// using split, to split the PATH env, extract each path in it
// using join, concat the name of the command to the name of the dir[i]
// access if its there, check
// and then do the rest
// bin/ /usr/bin
static char	*find_command_in_directories(char *cmd, char **dir)
{
	int		j;
	char	*full_cmd;
	char	*new_cm;

	j = 0;
	while (dir[j])
	{
		full_cmd = ft_strjoin(dir[j], "/");
		if (!full_cmd)
			return (NULL);
		new_cm = ft_strjoin(full_cmd, cmd);
		free(full_cmd);
		if (!new_cm)
			return (NULL);
		if (access(new_cm, F_OK) == 0)
			return (new_cm);
		free(new_cm);
		j++;
	}
	return (NULL);
}

static char	*get_path_from_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*search_command_in_path(char *cmd, char **envp)
{
	char	*path;
	char	**dir;
	char	*result;

	path = get_path_from_env(envp);
	if (!path)
		return (NULL);
	dir = ft_split(path, ':');
	if (!dir)
		return (NULL);
	result = find_command_in_directories(cmd, dir);
	free_split(dir);
	return (result);
}
