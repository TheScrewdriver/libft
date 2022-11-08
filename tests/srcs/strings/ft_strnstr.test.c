/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:51:28 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/12 14:20:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple_string)
{
	char	*string1 = "hello my name is Neo";
	char	*string2 = "is";
	char	*ptr;
	char	*ft_ptr;
	size_t	size = ft_strlen(string1);

	ptr = strnstr(string1, string2, size);
	ft_ptr = ft_strnstr(string1, string2, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(repetitive)
{
	char	*string1 = "OHoua hello my name is Ouah Ouah";
	char	*string2 = "Ouah";
	char	*ptr;
	char	*ft_ptr;
	size_t	size = ft_strlen(string1);

	ptr = strnstr(string1, string2, size);
	ft_ptr = ft_strnstr(string1, string2, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(not_found)
{
	char	*string1 = "hello my name is Neo";
	char	*string2 = "incredible";
	char	*ptr;
	char	*ft_ptr;
	size_t	size = ft_strlen(string1);

	ptr = strnstr(string1, string2, size);
	ft_ptr = ft_strnstr(string1, string2, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(not_found__size_too_big)
{
	char	*string1 = "hello my name is Neo";
	char	*string2 = "incredible";
	char	*ptr;
	char	*ft_ptr;
	size_t	size = 100;

	ptr = strnstr(string1, string2, size);
	ft_ptr = ft_strnstr(string1, string2, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(null_size)
{
	char	*string1 = "hello my name is Neo";
	char	*string2 = "Neo";
	char	*ptr;
	char	*ft_ptr;
	size_t	size = 0;

	ptr = strnstr(string1, string2, size);
	ft_ptr = ft_strnstr(string1, string2, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(empty_strings1)
{
	char	*string1 = "";
	char	*string2 = "";
	char	*ptr;
	char	*ft_ptr;
	size_t	size = 1;

	ptr = strnstr(string1, string2, size);
	ft_ptr = ft_strnstr(string1, string2, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(empty_strings2)
{
	char	*string1 = "hello";
	char	*string2 = "";
	char	*ptr;
	char	*ft_ptr;
	size_t	size = ft_strlen(string1);

	ptr = strnstr(string1, string2, size);
	ft_ptr = ft_strnstr(string1, string2, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(empty_strings3)
{
	char	*string1 = "";
	char	*string2 = "hello";
	char	*ptr;
	char	*ft_ptr;
	size_t	size = ft_strlen(string2);

	ptr = strnstr(string1, string2, size);
	ft_ptr = ft_strnstr(string1, string2, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

Suite	*ft_strnstr_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRNSTR");
	new = tcase_create("Result");
	tcase_add_test(new, simple_string);
	tcase_add_test(new, repetitive);
	tcase_add_test(new, not_found);
	tcase_add_test(new, not_found__size_too_big);
	tcase_add_test(new, null_size);
	tcase_add_test(new, empty_strings1);
	tcase_add_test(new, empty_strings2);
	tcase_add_test(new, empty_strings3);
	suite_add_tcase(s, new);
	return (s);
}
