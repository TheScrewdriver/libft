/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:18:50 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 11:11:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static void	fct1(unsigned int nb, char *s)
{
	if (nb % 2 == 0)
		*s = ft_toupper(*s);
	else
		*s = ft_tolower(*s);
}

static void	fct2(unsigned int nb, char *s)
{
	if (nb > 0 && nb % 5 == 0)
		*s = '5';
}

START_TEST(upper_even)
{
	char	string[] = "  hello my name is Neo   ";
	char	*expected_str = "  HeLlO My nAmE Is nEo   ";

	ft_striteri(string, &fct1);
	ck_assert_str_eq(expected_str, string);
}
END_TEST

START_TEST(take_five)
{
	char	string[] = "  hello my name is Neo   ";
	char	*expected_str = "  hel5o my5name5is N5o   ";

	ft_striteri(string, &fct2);
	ck_assert_str_eq(expected_str, string);
}
END_TEST

START_TEST(empty_string)
{
	char	string[] = "";
	char	*expected_str = "";

	ft_striteri(string, &fct2);
	ck_assert_str_eq(expected_str, string);
}
END_TEST

START_TEST(null_case1)
{
	char	string[] = "olala";
	char	*expected_str = "olala";

	ft_striteri(string, NULL);
	ck_assert_str_eq(expected_str, string);
}
END_TEST

START_TEST(null_case2)
{
	char	*string = NULL;
	char	*expected_str = NULL;

	ft_striteri(string, &fct1);
	ck_assert_ptr_eq(expected_str, string);
}
END_TEST

START_TEST(null_case3)
{
	char	*string = NULL;
	char	*expected_str = NULL;

	ft_striteri(string, NULL);
	ck_assert_ptr_eq(expected_str, string);
}
END_TEST

Suite	*ft_striteri_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRITERI");
	new = tcase_create("Result");
	tcase_add_test(new, upper_even);
	tcase_add_test(new, take_five);
	tcase_add_test(new, empty_string);
	tcase_add_test(new, null_case1);
	tcase_add_test(new, null_case2);
	tcase_add_test(new, null_case3);
	suite_add_tcase(s, new);
	return (s);
}
