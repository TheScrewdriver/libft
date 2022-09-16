/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:29:12 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 12:12:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple_nb)
{
	const char *str = "213";

	ck_assert_int_eq(ft_atoi(str), atoi(str));
}
END_TEST

START_TEST(empty_string)
{
	const char *str = "";

	ck_assert_int_eq(ft_atoi(str), atoi(str));
}
END_TEST

START_TEST(spaces1)
{
	const char *str = "    +   13";

	ck_assert_int_eq(ft_atoi(str), atoi(str));
}
END_TEST

START_TEST(spaces2)
{
	const char *str = "    ++13+";

	ck_assert_int_eq(ft_atoi(str), atoi(str));
}
END_TEST

START_TEST(spaces3)
{
	const char *str = "    +   2313 as      ";

	ck_assert_int_eq(ft_atoi(str), atoi(str));
}
END_TEST

START_TEST(negative)
{
	const char *str = "    -12313 as      ";

	ck_assert_int_eq(ft_atoi(str), atoi(str));
}
END_TEST

START_TEST(int_max)
{
	const char *str = "2147483647";

	ck_assert_int_eq(ft_atoi(str), atoi(str));
}
END_TEST

START_TEST(int_min)
{
	const char *str = "-2147483648";

	ck_assert_int_eq(ft_atoi(str), atoi(str));
}
END_TEST

START_TEST(int_min)
{
	const char *str = "-2147483648";

	ck_assert_int_eq(ft_atoi(str), atoi(str));
}
END_TEST

Suite	*ft_atoi_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_ATOI");
	new = tcase_create("Result");

	tcase_add_test(new, simple_nb);
	tcase_add_test(new, empty_string);
	tcase_add_test(new, spaces1);
	tcase_add_test(new, spaces2);
	tcase_add_test(new, spaces3);
	tcase_add_test(new, negative);
	tcase_add_test(new, int_max);
	tcase_add_test(new, int_min);

	suite_add_tcase(s, new);

	return (s);
}
