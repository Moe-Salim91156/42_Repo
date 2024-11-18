/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:12:04 by msalim            #+#    #+#             */
/*   Updated: 2024/11/18 19:54:20 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int argc, char **argv)
{
  int pipefd[2];
  pid_t pid;

  printf("%d\n",argc);
    if (pipe(pipefd) == -1)
    {
        perror("pipe creation failed");
        exit(EXIT_FAILURE);
    }
  pid = fork(); // create first child
  if (pid == 0)
  {
    first_child(pipefd, argv);
  }
  else
  {
    // this is from gpt, the problem was that im not output
    close(pipefd[1]);
        char buffer[1024];
        ssize_t bytes_read;
        while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytes_read); // Output to STDOUT
        }
        close(pipefd[0]);
        wait(NULL);
  }
  return (0);
}
// we set up the enviornment today
// now i should know how to create uni-directional communication between procesess
// using fork and pipe to shit at the same time
// and using the helpers to redirect input and output by dup2
// keep tracking and knowing how many file descreptors are there (actually)
// and then try to come up with solution to solve all of the project;
