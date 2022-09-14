/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:02:03 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/08 19:09:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(int_array)
{
	const size_t	size = 5;
	int				src[] = {1, 2, 3, 4, 5};
	int				dest[5];
	int				ft_src[] = {1, 2, 3, 4 ,5};
	int				ft_dest[5];

	memcpy(dest, src, size * sizeof(int));
	ft_memcpy(ft_dest, ft_src, size * sizeof(int));
	ck_assert_mem_eq(dest, ft_dest, size);
}
END_TEST

START_TEST(char_array)
{
	const size_t	size = 5;
	char			src[] = "lolilol";
	char			dest[5];
	char			ft_src[] = "lolilol";
	char			ft_dest[5];

	memcpy(dest, src, size * sizeof(char));
	ft_memcpy(ft_dest, ft_src, size * sizeof(char));
	ck_assert_mem_eq(dest, ft_dest, size);
}
END_TEST

START_TEST(null_size)
{
	const size_t	size = 0;
	char			src[] = "lolilol";
	char			dest[5];
	char			ft_src[] = "lolilol";
	char			ft_dest[5];

	memcpy(dest, src, size * sizeof(char));
	ft_memcpy(ft_dest, ft_src, size * sizeof(char));
	ck_assert_mem_eq(dest, ft_dest, size);
}
END_TEST

Suite	*ft_memcpy_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_MEMCPY");
	new = tcase_create("Result");
	tcase_add_test(new, int_array);
	tcase_add_test(new, char_array);
	tcase_add_test(new, null_size);
	suite_add_tcase(s, new);
	return (s);
}
