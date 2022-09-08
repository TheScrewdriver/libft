/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:12:45 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/08 18:57:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static int are_same_sign(const int a, const int b)
{
	return ((a == 0 && b == 0) ||  (a > 0 && b > 0) || (a < 0 && b < 0));
}

START_TEST(zero)
{
	const int c = 0;

	ck_assert_int_eq(are_same_sign(ft_isalnum(c), isalnum(c)), 1);
}
END_TEST

START_TEST(positive_nb1)
{
	const int c = 25;

	ck_assert_int_eq(are_same_sign(ft_isalnum(c), isalnum(c)), 1);
}
END_TEST

START_TEST(negative_nb)
{
	const int c = -54;

	ck_assert_int_eq(are_same_sign(ft_isalnum(c), isalnum(c)), 1);
}
END_TEST

START_TEST(uppercase1)
{
	const int c = 'A';

	ck_assert_int_eq(are_same_sign(ft_isalnum(c), isalnum(c)), 1);
}
END_TEST

START_TEST(uppercase2)
{
	const int c = 'M';

	ck_assert_int_eq(are_same_sign(ft_isalnum(c), isalnum(c)), 1);
}
END_TEST

START_TEST(lowercase)
{
	const int c = 'p';

	ck_assert_int_eq(are_same_sign(ft_isalnum(c), isalnum(c)), 1);
}
END_TEST

START_TEST(uchar_min)
{
	const int c = -UCHAR_MAX;

	ck_assert_int_eq(are_same_sign(ft_isalnum(c), isalnum(c)), 1);
}
END_TEST

START_TEST(uchar_max)
{
	const int c = UCHAR_MAX;

	ck_assert_int_eq(are_same_sign(ft_isalnum(c), isalnum(c)), 1);
}
END_TEST

START_TEST(beyond_uchar_max)
{
	const int c = UCHAR_MAX + 2;

	ck_assert_int_eq(are_same_sign(ft_isalnum(c), isalnum(c)), 1);
}
END_TEST

START_TEST(eof)
{
	const int c = EOF;

	ck_assert_int_eq(are_same_sign(ft_isalnum(c), isalnum(c)), 1);
}
END_TEST

Suite	*ft_isalnum_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_ISALNUM");
	new = tcase_create("Result");

	tcase_add_test(new, zero);
	tcase_add_test(new, positive_nb1);
	tcase_add_test(new, negative_nb);
	tcase_add_test(new, uppercase1);
	tcase_add_test(new, uppercase2);
	tcase_add_test(new, lowercase);
	tcase_add_test(new, uchar_min);
	tcase_add_test(new, uchar_max);
	tcase_add_test(new, beyond_uchar_max);
	tcase_add_test(new, eof);

	suite_add_tcase(s, new);

	return (s);
}
