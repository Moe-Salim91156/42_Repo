/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:32:38 by msalim            #+#    #+#             */
/*   Updated: 2024/11/24 19:20:59 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/*
 * function to handle the fds if it fails in any point;
 *
 * first child will use dup2 to duplicate the infile fd
 * to the STDIN fd, so its now the input
 * first child is gonna execute the first command
 *
 * second child will redirect the stdout fd to the
 * out file fd, so the output will be stored there
 * and is gonna execute the second command
 *
 * execute command 1 and 2 are kinda the same functionality
 * but with repsect to the small different between the first
 * and the second child implementation;
 *
 */
static void	handle(int fd, int pipefd[])
{
	if (fd == -1)
	{
		perror("file desc is not valid, -1 ");
		close(pipefd[0]);
		close(pipefd[1]);
		close(fd);
		exit(EXIT_FAILURE);
	}
}

static void	execute_command(char **argv, int flag)
{
	char	*input;
	char	**splitted;
	char	*cmd;

	if (flag == 1)
		input = argv[2];
	else
		input = argv[3];
	splitted = ft_split(input, ' ');
	cmd = ft_strjoin("/bin/", splitted[0]);
	execve(cmd, splitted, NULL);
	free_all(splitted, cmd);
}

void	first_child(int pipefd[], char **argv)
{
	int	dup2_value;
	int	in_fd;

	in_fd = open(argv[1], O_RDONLY);
	if (in_fd == -1)
	{
		perror("open infile failed");
		close(pipefd[0]);
		close(pipefd[1]);
		exit(1);
	}
	close(pipefd[0]);
	dup2(in_fd, STDIN_FILENO);
	handle(in_fd, pipefd);
	close(in_fd);
	dup2_value = dup2(pipefd[1], STDOUT_FILENO);
	if (dup2_value == -1)
	{
		perror("dup the pipe failed");
		close(pipefd[0]);
		close(pipefd[1]);
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	execute_command(argv, 1);
}

void	second_child(int pipefd[], char **argv)
{
	int	out_fd;

	out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	handle(out_fd, pipefd);
	close(pipefd[1]);
	if ((dup2(pipefd[0], STDIN_FILENO)) == -1)
	{
		perror("dup the pipefd[0] failed");
		close(pipefd[0]);
		close(pipefd[1]);
		exit(EXIT_FAILURE);
	}
	if ((dup2(out_fd, STDOUT_FILENO)) == -1)
	{
		perror("dup the out_fd failed");
		close(pipefd[0]);
		close(pipefd[1]);
		exit(EXIT_FAILURE);
	}
	close(out_fd);
	close(pipefd[0]);
	execute_command(argv, 2);
}
/* first child will do :
 step1;
 --> DONE  1. take the content of the input file
 --> DONE  2. redirect stdin to infile_fd;
  question : do i need to close the pipefd[1] here?
  or i should leave it open for the second child ? or does it matter ? 3. close;

step2 ;
--> DONE  1. redirect stdout to the write end of the pipe
2. execute the command
*/
