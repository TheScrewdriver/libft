/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:26:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 10:01:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static char	fct1(unsigned int nb, char c)
{
	if (nb % 2 == 0)
		c = ft_toupper(c);
	else
		c = ft_tolower(c);
	return (c);
}

static char	fct2(unsigned int nb, char c)
{
	if (nb != 0 && nb % 5 == 0)
		c = '5';
	return (c);
}

START_TEST(upper_even)
{
	char	*string = "  hello my name is Neo   ";
	char	*expected_str = "  HeLlO My nAmE Is nEo   ";
	char	*mapi;

	mapi = ft_strmapi(string, &fct1);
	ck_assert_str_eq(expected_str, mapi);
	free(mapi);
}
END_TEST

START_TEST(take_five)
{
	char	*string = "  hello my name is Neo   ";
	char	*expected_str = "  hel5o my5name5is N5o   ";
	char	*mapi;

	mapi = ft_strmapi(string, &fct2);
	ck_assert_str_eq(expected_str, mapi);
	free(mapi);
}
END_TEST

START_TEST(empty_string)
{
	char	*string = "";
	char	*expected_str = "";
	char	*mapi;

	mapi = ft_strmapi(string, &fct2);
	ck_assert_str_eq(expected_str, mapi);
	free(mapi);
}
END_TEST

Suite	*ft_strmapi_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRMAPI");
	new = tcase_create("Result");
	tcase_add_test(new, upper_even);
	tcase_add_test(new, take_five);
	tcase_add_test(new, empty_string);
/*
	tcase_add_test(new, same_strings);
	tcase_add_test(new, only_charset);
	tcase_add_test(new, empty_string1);
	tcase_add_test(new, empty_string2);
	tcase_add_test(new, empty_set);
	tcase_add_test(new, little_set);
*/
	suite_add_tcase(s, new);
	return (s);
}
