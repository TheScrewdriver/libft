/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:52:18 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 14:21:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple_string)
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

START_TEST(little_set)
{
	char	*string1 = "ooooaaaaaoabuaaaaargero";
	char	*set = "ao";
	char	*expected_str = "buaaaaarger";
	char	*trim;

	trim = ft_strtrim(string1, set);
	ck_assert_str_eq(expected_str, trim);
	free(trim);
}
END_TEST

START_TEST(null_case1)
{
	char	*string1 = NULL;
	char	*set = "ao";
	char	*expected_str = NULL;
	char	*trim;

	trim = ft_strtrim(string1, set);
	ck_assert_ptr_eq(expected_str, trim);
}
END_TEST

START_TEST(null_case2)
{
	char	*string1 = NULL;
	char	*set = NULL;
	char	*expected_str = NULL;
	char	*trim;

	trim = ft_strtrim(string1, set);
	ck_assert_ptr_eq(expected_str, trim);
}
END_TEST

START_TEST(null_case3)
{
	char	*string1 = "ooooaaaaaoabuaaaaargero";
	char	*set = NULL;
	char	*expected_str = "ooooaaaaaoabuaaaaargero";
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
	tcase_add_test(new, simple_string);
	tcase_add_test(new, only_charset);
	tcase_add_test(new, empty_string1);
	tcase_add_test(new, empty_string2);
	tcase_add_test(new, empty_set);
	tcase_add_test(new, little_set);
	tcase_add_test(new, null_case1);
	tcase_add_test(new, null_case2);
	tcase_add_test(new, null_case3);
	suite_add_tcase(s, new);
	return (s);
}
