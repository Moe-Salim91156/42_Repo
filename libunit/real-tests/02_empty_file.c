/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_empty_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:44:02 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 18:42:54 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h"

int	empty_file_test(void)
{
	int		fd;
	char	*line;

	fd = open("real-tests/testfiles/empty.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	close(fd);
	if (line == NULL)
		return (0);
	free(line);
	return (-1);
}
