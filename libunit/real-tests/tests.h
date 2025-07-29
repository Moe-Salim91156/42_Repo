/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:56:02 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 18:58:39 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int	basic_line_test(void);
int	empty_file_test(void);
int	long_line_test(void);
int	test_strcpy_basic(void);
int	test_strcpy_empty(void);
int	test_strncmp_different(void);
int	test_strncmp_equal(void);
int	test_atoi_basic(void);
int	test_atoi_invalid(void);
int	test_atoi_negative(void);
int	test_memset_zero_len(void);
int	test_memset_basic(void);
int	test_strdup_empty(void);
int	test_strdup_basic(void);
int	test_isalpha_basic(void);
int	test_bzero_zero_len(void);
int	test_bzero_basic(void);
int	launcher(void);
#endif
