/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:57:26 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/11 13:00:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple_string)
{
	char	*string = "hello my name is Neo";
	char	c = 'l';
	char	*ptr;
	char	*ft_ptr;

	ptr = strrchr(string, c);
	ft_ptr = ft_strrchr(string, c);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(repetitive_string)
{
	char	*string = "lhello mlololololollllllllllaaaaklp";
	char	c = 'l';
	char	*ptr;
	char	*ft_ptr;

	ptr = strrchr(string, c);
	ft_ptr = ft_strrchr(string, c);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(empty_string)
{
	char	*string = "";
	char	c = 'l';
	char	*ptr;
	char	*ft_ptr;

	ptr = strrchr(string, c);
	ft_ptr = ft_strrchr(string, c);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(search_for_null_char)
{
	char	*string = "yolo";
	char	c = '\0';
	char	*ptr;
	char	*ft_ptr;

	ptr = strrchr(string, c);
	ft_ptr = ft_strrchr(string, c);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST
Suite	*ft_strrchr_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRRCHR");
	new = tcase_create("Result");
	tcase_add_test(new, simple_string);
	tcase_add_test(new, repetitive_string);
	tcase_add_test(new, empty_string);
	tcase_add_test(new, search_for_null_char);
	suite_add_tcase(s, new);
	return (s);
}
