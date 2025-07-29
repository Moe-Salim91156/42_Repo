/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:35:40 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 18:44:08 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/libunit.h"
#include "tests.h"

int	launcher(void)
{
	t_unit_test	*tests;

	tests = NULL;
	load_test(&tests, "ft_GNL basic text", &basic_line_test);
	load_test(&tests, "ft_GNL empty file test", &empty_file_test);
	load_test(&tests, "ft_strcpy basic_test", &test_strcpy_basic);
	load_test(&tests, "ft_strcpy empty_test", &test_strcpy_empty);
	load_test(&tests, "ft_strncmp_equal_test", &test_strncmp_equal);
	load_test(&tests, "ft_strncmp_different_test", &test_strncmp_different);
	load_test(&tests, "ft_atoi_basic_test", &test_atoi_basic);
	load_test(&tests, "ft_atoi_negative_test", &test_atoi_negative);
	load_test(&tests, "ft_memset basic_test", &test_memset_basic);
	load_test(&tests, "ft_memset zero_len_test", &test_memset_zero_len);
	load_test(&tests, "ft_strdup_basic_test", &test_strdup_basic);
	load_test(&tests, "ft_strdup_empty_test", &test_strdup_empty);
	load_test(&tests, "ft_isalpha basic", &test_isalpha_basic);
	load_test(&tests, "ft_bzero basic tests", &test_bzero_basic);
	load_test(&tests, "ft_bzero zero len tests", &test_bzero_zero_len);
	return (launch_tests(&tests));
}
