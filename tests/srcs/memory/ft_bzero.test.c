/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:41:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/08 18:45:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(int_array)
{
	const size_t	size = 5;
	int				array[5];
	int				ft_array[5];

	bzero(array, size * sizeof(int));
	ft_bzero(ft_array, size * sizeof(int));
	ck_assert_mem_eq(array, ft_array, size);
}
END_TEST

START_TEST(char_array)
{
	const size_t	size = 2;
	char			array[] = "hello";
	char			ft_array[] = "hello";

	bzero(array, size * sizeof(char));
	ft_bzero(ft_array, size * sizeof(char));
	ck_assert_mem_eq(array, ft_array, size);
}
END_TEST

START_TEST(null_size)
{
	const size_t	size = 0;
	char			array[] = "hello";
	char			ft_array[] = "hello";

	bzero(array, size * sizeof(char));
	ft_bzero(ft_array, size * sizeof(char));
	ck_assert_mem_eq(array, ft_array, size);
}
END_TEST

Suite	*ft_bzero_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_BZERO");
	new = tcase_create("Result");
	tcase_add_test(new, int_array);
	tcase_add_test(new, char_array);
	tcase_add_test(new, null_size);
	suite_add_tcase(s, new);
	return (s);
}
