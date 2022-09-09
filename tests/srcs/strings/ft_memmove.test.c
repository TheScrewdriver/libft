/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:49:42 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/09 11:37:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(int_array)
{
	const size_t	size = 5;
	const size_t	dest_size = 5;
	int				src[] = {1, 2, 3, 4, 5};
	int				dest[5];
	int				ft_src[] = {1, 2, 3, 4 ,5};
	int				ft_dest[5];

	memmove(dest, src, size * sizeof(int));
	ft_memmove(ft_dest, ft_src, size * sizeof(int));
	ck_assert_mem_eq(dest, ft_dest, dest_size);
}
END_TEST

START_TEST(char_array)
{
	const size_t	size = 5;
	const size_t	dest_size = 5;
	char			src[] = "lolilol";
	char			dest[5];
	char			ft_src[] = "lolilol";
	char			ft_dest[5];

	memmove(dest, src, size * sizeof(char));
	ft_memmove(ft_dest, ft_src, size * sizeof(char));
	ck_assert_mem_eq(dest, ft_dest, dest_size);
}
END_TEST

START_TEST(overlap)
{
	const size_t	size = 5;
	const size_t	dest_size = 11;
	char			src[] = "Start stop";
	char			*dest = src;
	char			ft_src[] = "Start stop";
	char			*ft_dest = ft_src;

	memmove(src + 2, src, size * sizeof(char));
	ft_memmove(ft_src + 2, ft_src, size * sizeof(char));
	printf("src -----> %s; dest ------> %s\n", src , dest);
	printf("ft_src --> %s; ft_dest ---> %s\n", ft_src , ft_dest);
	ck_assert_mem_eq(dest, ft_dest, dest_size);
}
END_TEST

START_TEST(null_size)
{
	const size_t	size = 0;
	const size_t	dest_size = 0;
	char			src[] = "lolilol";
	char			dest[5];
	char			ft_src[] = "lolilol";
	char			ft_dest[5];

	memmove(dest, src, size * sizeof(char));
	ft_memmove(ft_dest, ft_src, size * sizeof(char));
	ck_assert_mem_eq(dest, ft_dest, dest_size);
}
END_TEST

Suite	*ft_memmove_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_MEMMOVE");
	new = tcase_create("Result");
	tcase_add_test(new, int_array);
	tcase_add_test(new, char_array);
	tcase_add_test(new, overlap);
	tcase_add_test(new, null_size);
	suite_add_tcase(s, new);
	return (s);
}
