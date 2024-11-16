/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:32:38 by msalim            #+#    #+#             */
/*   Updated: 2024/11/16 19:26:45 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "pipex.h"

void  first_child(int pipefd[])
{
  int in_fd;

  in_fd = open("infile", O_RDONLY);
  if (in_fd == -1)
  {
    perror("open infile failed");
    exit(EXIT_FAILURE);
  }
  dup2(in_fd, STDIN_FILENO); // redirect the stdin to the infile step here 
  close(in_fd); // close the in_fd we dont need it anymore
  // redirect the stdout to the write end step here 
  dup2(pipefd[1], STDOUT_FILENO);
  close(pipefd[0]); // close this because we dont need it
  // execute the command

}
//first child will do : 
    // step1;
// --> DONE  1. take the content of the input file
// --> DONE  2. redirect stdin to infile_fd;
//  question : do i need to close the pipefd[1] here? or i should leave it open for the second child ? or does it matter ? 3. close;
//
//  step2 ; 
// --> DONE  1. redirect stdout to the write end of the pipe
//  2. execute the command
