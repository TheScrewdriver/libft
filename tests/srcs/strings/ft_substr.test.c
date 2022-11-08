/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:14:57 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/14 16:52:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple_string)
{
	char	*input_string = "hello my name is Neo";
	char	*expected_string = "is Neo";
	size_t	start = 14;
	size_t	len = 50;
	char	*substr;

	substr = ft_substr(input_string, start, len);
	ck_assert_str_eq(expected_string, substr);
	free(substr);
}
END_TEST

START_TEST(empty_string)
{
	char	*input_string = "";
	char	*expected_string = "";
	size_t	start = 0;
	size_t	len = 50;
	char	*substr;

	substr = ft_substr(input_string, start, len);
	ck_assert_str_eq(expected_string, substr);
	free(substr);
}
END_TEST

START_TEST(little_len)
{
	char	*input_string = "I would like to buy a hamburger";
	char	*expected_string = "buy";
	size_t	start = 16;
	size_t	len = 3;
	char	*substr;

	substr = ft_substr(input_string, start, len);
	ck_assert_str_eq(expected_string, substr);
	free(substr);
}
END_TEST

START_TEST(big_len)
{
	char	*input_string = "lol";
	char	*expected_string = "ol";
	size_t	start = 1;
	size_t	len = 12314;
	char	*substr;

	substr = ft_substr(input_string, start, len);
	ck_assert_str_eq(expected_string, substr);
	free(substr);
}
END_TEST

START_TEST(start_too_far)
{
	char	*input_string = "lol";
	char	*expected_string = "";
	size_t	start = 14;
	size_t	len = 14;
	char	*substr;

	substr = ft_substr(input_string, start, len);
	ck_assert_str_eq(expected_string, substr);
	free(substr);
}
END_TEST

Suite	*ft_substr_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_SUBSTR");
	new = tcase_create("Result");
	tcase_add_test(new, simple_string);
	tcase_add_test(new, empty_string);
	tcase_add_test(new, little_len);
	tcase_add_test(new, big_len);
	tcase_add_test(new, start_too_far);
	suite_add_tcase(s, new);
	return (s);
}
