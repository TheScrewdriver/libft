/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:09:02 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/01 12:56:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(test_simple1)
{
	const char	*str = "Hello";

	ck_assert_int_eq(ft_strlen(str) == strlen(str), 1);
}
END_TEST

START_TEST(test_simple2)
{
	const char	*str = "";

	ck_assert_int_eq(ft_strlen(str) == strlen(str), 1);
}
END_TEST

START_TEST(test_simple3)
{
	const char	*str = "\0\0\0\0";

	ck_assert_int_eq(ft_strlen(str) == strlen(str), 1);
}
END_TEST

Suite	*ft_strlen_suite(void)
{
	Suite	*s;
	TCase	*tc_core;

	s = suite_create("FT_STRLEN");
	tc_core = tcase_create("Result");

	tcase_add_test(tc_core, test_simple1);
	tcase_add_test(tc_core, test_simple2);
	tcase_add_test(tc_core, test_simple3);
	suite_add_tcase(s, tc_core);

	return (s);
}
