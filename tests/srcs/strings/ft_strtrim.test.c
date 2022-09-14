/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:52:18 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/14 19:04:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(same_strings)
{
	char	*string1 = "            hello my name is Neo   ";
	char	*set = "  ";
	char	*expected_str = "hello my name is Neo";
	char	*trim;

	trim = ft_strtrim(string1, set);
	ck_assert_str_eq(expected_str, trim);
	free(trim);
}
END_TEST

START_TEST(only_charset)
{
	char	*string1 = "             ";
	char	*set = "  ";
	char	*expected_str = "";
	char	*trim;

	trim = ft_strtrim(string1, set);
	ck_assert_str_eq(expected_str, trim);
	free(trim);
}
END_TEST

START_TEST(empty_string1)
{
	char	*string1 = "";
	char	*set = "";
	char	*expected_str = "";
	char	*trim;

	trim = ft_strtrim(string1, set);
	ck_assert_str_eq(expected_str, trim);
	free(trim);
}
END_TEST

START_TEST(empty_string2)
{
	char	*string1 = "";
	char	*set = "burger";
	char	*expected_str = "";
	char	*trim;

	trim = ft_strtrim(string1, set);
	ck_assert_str_eq(expected_str, trim);
	free(trim);
}
END_TEST

START_TEST(empty_set)
{
	char	*string1 = "burger";
	char	*set = "";
	char	*expected_str = "burger";
	char	*trim;

	trim = ft_strtrim(string1, set);
	ck_assert_str_eq(expected_str, trim);
	free(trim);
}
END_TEST

Suite	*ft_strtrim_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRTRIM");
	new = tcase_create("Result");
	tcase_add_test(new, same_strings);
	tcase_add_test(new, only_charset);
	tcase_add_test(new, empty_string1);
	tcase_add_test(new, empty_string2);
	tcase_add_test(new, empty_set);
	suite_add_tcase(s, new);
	return (s);
}
