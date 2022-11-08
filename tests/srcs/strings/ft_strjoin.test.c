/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:47:46 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/14 18:08:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(same_strings)
{
	char	*string1 = "hello my name is Neo";
	char	*string2 = "hello my name is Neo";
	char	*expected_str = "hello my name is Neohello my name is Neo";
	char	*join;

	join = ft_strjoin(string1, string2);
	ck_assert_str_eq(expected_str, join);
	free(join);
}
END_TEST

START_TEST(empty_string1)
{
	char	*string1 = "";
	char	*string2 = "";
	char	*expected_str = "";
	char	*join;

	join = ft_strjoin(string1, string2);
	ck_assert_str_eq(expected_str, join);
	free(join);
}
END_TEST

START_TEST(empty_string2)
{
	char	*string1 = "burger";
	char	*string2 = "";
	char	*expected_str = "burger";
	char	*join;

	join = ft_strjoin(string1, string2);
	ck_assert_str_eq(expected_str, join);
	free(join);
}
END_TEST

START_TEST(empty_string3)
{
	char	*string1 = "";
	char	*string2 = "burger";
	char	*expected_str = "burger";
	char	*join;

	join = ft_strjoin(string1, string2);
	ck_assert_str_eq(expected_str, join);
	free(join);
}
END_TEST

Suite	*ft_strjoin_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRJOIN");
	new = tcase_create("Result");
	tcase_add_test(new, same_strings);
	tcase_add_test(new, empty_string1);
	tcase_add_test(new, empty_string2);
	tcase_add_test(new, empty_string3);
	suite_add_tcase(s, new);
	return (s);
}
