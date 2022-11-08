/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:44:35 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/14 17:50:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(char_array)
{
	char			src[] = "lolilol";
	char			dest[10];
	char			ft_src[] = "lolilol";
	char			ft_dest[10];

	strcpy(dest, src);
	ft_strcpy(ft_dest, ft_src);
	ck_assert_str_eq(dest, ft_dest);
}
END_TEST

START_TEST(empty_string)
{
	char			src[] = "";
	char			dest[10];
	char			ft_src[] = "";
	char			ft_dest[10];

	strcpy(dest, src);
	ft_strcpy(ft_dest, ft_src);
	ck_assert_str_eq(dest, ft_dest);
}
END_TEST

Suite	*ft_strcpy_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRCPY");
	new = tcase_create("Result");
	tcase_add_test(new, char_array);
	tcase_add_test(new, empty_string);
	suite_add_tcase(s, new);
	return (s);
}
