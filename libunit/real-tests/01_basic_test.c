/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrfa3i <alrfa3i@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:43:31 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 19:31:47 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h"

int	basic_line_test(void)
{
	int		fd;
	char	*line;

	fd = open("real-tests/testfiles/basic.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (ft_strcmp(line, "Hello World\n") == 0)
		return (0);
	else
		return (1);
}
