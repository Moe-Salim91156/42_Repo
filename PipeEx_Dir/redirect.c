/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:32:38 by msalim            #+#    #+#             */
/*   Updated: 2024/11/18 19:53:11 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "pipex.h"
void  first_child(int pipefd[], char **argv)
{
  int in_fd;

  in_fd = open(argv[1], O_RDONLY);
  printf("file : %s", argv[1]);
  if (in_fd == -1)
  {
    perror("open infile failed");
    exit(EXIT_FAILURE);
  }
  dup2(in_fd, STDIN_FILENO); // redirect the stdin to the infile step here 
  close(in_fd); // close the in_fd we dont need it anymore
  dup2(pipefd[1], STDOUT_FILENO);
  close(pipefd[1]); // close this because we dont need it
  close(pipefd[0]); // close this because we dont need it
  execute_command(argv);
  // execute the command
}

void  execute_command(char **argv)
{
  char  *input;
  char  **splitted;
  char  *cmd;

  input = argv[2];
  splitted = ft_split(input, ' ');
  cmd = ft_strjoin("/bin/", splitted[0]);
  printf("the cmd is %s\n", cmd);
  execve(cmd, splitted, NULL);
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
