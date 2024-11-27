/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:12:28 by msalim            #+#    #+#             */
/*   Updated: 2024/11/27 14:13:24 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

char	*search_command_in_path(char *cmd, char **envp);
void	free_split(char **split);
void	free_strjoin(char *joined);
void	free_all(char **l, char *k);
void	free_aall(char **split, char *joined);
void	first_child(int pipefd[], char **av, char **ap);
void	second_child(int pipefd[], char **av, char **env);
#endif
