/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:30:41 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 12:07:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static bool	are_same_strarray(char **array1, char **array2)
{
	while (*array1 != NULL && *array2 != NULL)
	{
		++array1;
		++array2;
	}
	return (*array1 == NULL && *array2 == NULL);
}

static void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		++i;
	}
	free(strs);
}

START_TEST(simple_string1)
{
	char	*string = "            hello my name is Neo   ";
	char	set = ' ';
	char	*expected_str[] = {"hello", "my", "name", "is", "Neo", NULL};
	char	**split;

	split = ft_split(string, set);
	ck_assert_int_eq(are_same_strarray(split, expected_str), 1);
	free_strs(split);
}
END_TEST

START_TEST(no_set)
{
	char	*string = "hellomynameisNeo";
	char	set = ' ';
	char	*expected_str[] = {"hellomynameisNeo", NULL};
	char	**split;

	split = ft_split(string, set);
	ck_assert_int_eq(are_same_strarray(split, expected_str), 1);
	free_strs(split);
}
END_TEST

START_TEST(empty_string1)
{
	char	*string = "               ";
	char	set = ' ';
	char	*expected_str[] = {NULL};
	char	**split;

	split = ft_split(string, set);
	ck_assert_int_eq(are_same_strarray(split, expected_str), 1);
	free_strs(split);
}
END_TEST

START_TEST(empty_string2)
{
	char	*string = "";
	char	set = ' ';
	char	*expected_str[] = {NULL};
	char	**split;

	split = ft_split(string, set);
	ck_assert_int_eq(are_same_strarray(split, expected_str), 1);
	free_strs(split);
}
END_TEST

START_TEST(empty_string3)
{
	char	*string = "";
	char	set = '\0';
	char	*expected_str[] = {NULL};
	char	**split;

	split = ft_split(string, set);
	ck_assert_int_eq(are_same_strarray(split, expected_str), 1);
	free_strs(split);
}
END_TEST

START_TEST(null_case)
{
	char	*string = NULL;
	char	set = 'a';
	char	**expected_str = NULL;
	char	**split;

	split = ft_split(string, set);
	ck_assert_ptr_eq(expected_str, split);
}
END_TEST

Suite	*ft_split_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRSPLIT");
	new = tcase_create("Result");
	tcase_add_test(new, simple_string1);
	tcase_add_test(new, no_set);
	tcase_add_test(new, empty_string1);
	tcase_add_test(new, empty_string2);
	tcase_add_test(new, empty_string3);
	tcase_add_test(new, null_case);
	suite_add_tcase(s, new);
	return (s);
}
