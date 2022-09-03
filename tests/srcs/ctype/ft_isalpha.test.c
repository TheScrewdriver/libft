/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:15:21 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/03 09:49:50 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static int are_same_sign(const int a, const int b)
{
	return ((a == 0 && b == 0) ||  (a > 0 && b > 0) || (a < 0 && b < 0));
}

START_TEST(simple_test1)
{
	const int c = 0;

	ck_assert_int_eq(are_same_sign(ft_isalpha(c), isalpha(c)), 1);
}
END_TEST

START_TEST(simple_test2)
{
	const int c = 25;

	ck_assert_int_eq(are_same_sign(ft_isalpha(c), isalpha(c)), 1);
}
END_TEST

START_TEST(simple_test3)
{
	const int c = 'A';

	ck_assert_int_eq(are_same_sign(ft_isalpha(c), isalpha(c)), 1);
}
END_TEST

START_TEST(simple_test4)
{
	const int c = -54;

	ck_assert_int_eq(are_same_sign(ft_isalpha(c), isalpha(c)), 1);
}
END_TEST

START_TEST(simple_test5)
{
	const int c = -256;

	ck_assert_int_eq(are_same_sign(ft_isalpha(c), isalpha(c)), 1);
}
END_TEST

Suite	*ft_isalpha_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_ISALPHA");
	new = tcase_create("Result");

	tcase_add_test(new, simple_test1);
	tcase_add_test(new, simple_test2);
	tcase_add_test(new, simple_test3);
	tcase_add_test(new, simple_test4);
	tcase_add_test(new, simple_test5);

	suite_add_tcase(s, new);

	return (s);
}
