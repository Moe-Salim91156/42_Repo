/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:12:04 by msalim            #+#    #+#             */
/*   Updated: 2025/07/29 16:37:01 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * function to protect the process id if its fails to fork;
 * main function just create the child processes and pass it to
 * their respective function;
 */
static void	protect(pid_t pid, int pipefd[])
{
	if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		printf("something");
		perror("fork failed");
		exit(errno);
	}
}

static void	handle_pipe(int pipefd[])
{
	if (pipe(pipefd) == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		perror("pipe creation failed");
		exit(errno);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		exit(1);
	handle_pipe(pipefd);
	pid1 = fork();
	protect(pid1, pipefd);
	if (pid1 == 0)
		first_child(pipefd, argv, envp);
	pid2 = fork();
	protect(pid2, pipefd);
	if (pid2 == 0)
		second_child(pipefd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
/*we set up the enviornment today
 now i should know how to create uni-directional communication between procesess
 using fork and pipe to shit at the same time
 and using the helpers to redirect input and output by dup2
 keep tracking and knowing how many file descreptors are there (actually)
and then try to come up with solution to solve all of the	project;
*/
