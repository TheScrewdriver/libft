/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:09:02 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/03 09:15:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple_test1)
{
	const char	*str = "Hello";

	ck_assert_int_eq(ft_strlen(str) == strlen(str), 1);
}
END_TEST

START_TEST(simple_test2)
{
	const char	*str = "";

	ck_assert_int_eq(ft_strlen(str) == strlen(str), 1);
}
END_TEST

START_TEST(simple_test3)
{
	const char	*str = "\0\0\0\0";

	ck_assert_int_eq(ft_strlen(str) == strlen(str), 1);
}
END_TEST

Suite	*ft_strlen_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRLEN");
	new = tcase_create("Result");

	tcase_add_test(new, simple_test1);
	tcase_add_test(new, simple_test2);
	tcase_add_test(new, simple_test3);
	suite_add_tcase(s, new);

	return (s);
}
