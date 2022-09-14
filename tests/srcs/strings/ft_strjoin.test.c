/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:47:46 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/14 17:48:24 by rbroque          ###   ########.fr       */
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
/*
START_TEST(same_beginning1)
{
	char	*string1 = "hello my name is Ouah";
	char	*string2 = "hello my name is Neo";
	size_t	size = 21;
	int		result;
	int		ft_result;

	result = strjoin(string1, string2, size);
	ft_result = ft_strjoin(string1, string2, size);
	ck_assert_int_eq(are_same_sign(result, ft_result), 1);
}
END_TEST

START_TEST(same_beginning2)
{
	char	*string1 = "hello my name is Neo";
	char	*string2 = "hello my name is Ouah";
	size_t	size = 21;
	int		result;
	int		ft_result;

	result = strjoin(string1, string2, size);
	ft_result = ft_strjoin(string1, string2, size);
	ck_assert_int_eq(are_same_sign(result, ft_result), 1);
}
END_TEST

START_TEST(empty_strings)
{
	char	*string1 = "";
	char	*string2 = "";
	size_t	size = 1;
	int		result;
	int		ft_result;

	result = strjoin(string1, string2, size);
	ft_result = ft_strjoin(string1, string2, size);
	ck_assert_int_eq(are_same_sign(result, ft_result), 1);
}
END_TEST
*/
Suite	*ft_strjoin_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRJOIN");
	new = tcase_create("Result");
	tcase_add_test(new, same_strings);
//	tcase_add_test(new, same_beginning1);
//	tcase_add_test(new, same_beginning2);
//	tcase_add_test(new, empty_strings);
	suite_add_tcase(s, new);
	return (s);
}
