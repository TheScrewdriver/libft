/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:27:30 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/10 12:43:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(char_array)
{
	const size_t	size = 5;
	char			src[] = "lolilol";
	char			dest[5];
	char			ft_src[] = "lolilol";
	char			ft_dest[5];

	strlcpy(dest, src, size * sizeof(char));
	ft_strlcpy(ft_dest, ft_src, size * sizeof(char));
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

	strlcpy(dest, src, size * sizeof(char));
	ft_strlcpy(ft_dest, ft_src, size * sizeof(char));
	ck_assert_mem_eq(dest, ft_dest, size);
}
END_TEST

Suite	*ft_strlcpy_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRLCPY");
	new = tcase_create("Result");
	tcase_add_test(new, char_array);
	tcase_add_test(new, null_size);
	suite_add_tcase(s, new);
	return (s);
}
