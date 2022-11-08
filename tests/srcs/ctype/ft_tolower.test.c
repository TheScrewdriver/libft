/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:13:15 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/11 12:21:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(zero)
{
	const int c = 0;

	ck_assert_int_eq(ft_tolower(c), tolower(c));
}
END_TEST

START_TEST(positive_nb1)
{
	const int c = 25;

	ck_assert_int_eq(ft_tolower(c), tolower(c));
}
END_TEST

START_TEST(uppercase1)
{
	const int c = 'A';

	ck_assert_int_eq(ft_tolower(c), tolower(c));
}
END_TEST

START_TEST(uppercase2)
{
	const int c = 'M';

	ck_assert_int_eq(ft_tolower(c), tolower(c));
}
END_TEST

START_TEST(lowercase)
{
	const int c = 'p';

	ck_assert_int_eq(ft_tolower(c), tolower(c));
}
END_TEST

START_TEST(uchar_min)
{
	const int c = -UCHAR_MAX;

	ck_assert_int_eq(ft_tolower(c), tolower(c));
}
END_TEST

START_TEST(uchar_max)
{
	const int c = UCHAR_MAX;

	ck_assert_int_eq(ft_tolower(c), tolower(c));
}
END_TEST

START_TEST(beyond_uchar_max)
{
	const int c = UCHAR_MAX + 2;

	ck_assert_int_eq(ft_tolower(c), tolower(c));
}
END_TEST

START_TEST(eof)
{
	const int c = EOF;

	ck_assert_int_eq(ft_tolower(c), tolower(c));
}
END_TEST

Suite	*ft_tolower_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_TOLOWER");
	new = tcase_create("Result");

	tcase_add_test(new, zero);
	tcase_add_test(new, positive_nb1);
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
