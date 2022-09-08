/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:53:45 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/08 18:36:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(int_array)
{
	const size_t	size = 5;
	const int		content = 4;
	int				array[5];
	int				ft_array[5];

	memset(array, content, size * sizeof(int));
	ft_memset(ft_array, content, size * sizeof(int));
	ck_assert_mem_eq(array, ft_array, size);
}
END_TEST

START_TEST(char_array)
{
	const size_t	size = 2;
	const int		content = 'a';
	char			array[] = "hello";
	char			ft_array[] = "hello";

	memset(array, content, size * sizeof(char));
	ft_memset(ft_array, content, size * sizeof(char));
	ck_assert_mem_eq(array, ft_array, size);
}
END_TEST

START_TEST(null_size)
{
	const size_t	size = 0;
	const int		content = 'a';
	char			array[] = "hello";
	char			ft_array[] = "hello";

	memset(array, content, size * sizeof(char));
	ft_memset(ft_array, content, size * sizeof(char));
	ck_assert_mem_eq(array, ft_array, size);
}
END_TEST

START_TEST(int_max_content)
{
	const size_t	size = 4;
	const int		content = INT_MAX;
	char			array[4];
	char			ft_array[4];

	memset(array, content, size * sizeof(char));
	ft_memset(ft_array, content, size * sizeof(char));
	ck_assert_mem_eq(array, ft_array, size);
}
END_TEST

Suite	*ft_memset_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_MEMSET");
	new = tcase_create("Result");
	tcase_add_test(new, int_array);
	tcase_add_test(new, char_array);
	tcase_add_test(new, null_size);
	tcase_add_test(new, int_max_content);
	suite_add_tcase(s, new);
	return (s);
}
