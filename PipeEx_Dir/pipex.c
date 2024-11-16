/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:12:04 by msalim            #+#    #+#             */
/*   Updated: 2024/11/16 19:37:34 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
  int pipefd[2];
  pid_t pid;

  if (pipe(pipefd) == -1)
  {
    perror("pipe failed");
    exit(-1);
  }
  pid = fork(); // create first child
  if (pid == 0)
    first_child(pipefd);
  else
    wait(NULL);
  return (0);
}



// we set up the enviornment today
// now i should know how to create uni-directional communication between procesess
// using fork and pipe to shit at the same time
// and using the helpers to redirect input and output by dup2
// keep tracking and knowing how many file descreptors are there (actually)
// and then try to come up with solution to solve all of the project;
