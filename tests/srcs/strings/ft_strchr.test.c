/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:32:14 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/11 12:44:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple_string)
{
	char	*string = "hello my name is Neo";
	char	c = 'l';
	char	*ptr;
	char	*ft_ptr;

	ptr = strchr(string, c);
	ft_ptr = ft_strchr(string, c);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(empty_string)
{
	char	*string = "";
	char	c = 'l';
	char	*ptr;
	char	*ft_ptr;

	ptr = strchr(string, c);
	ft_ptr = ft_strchr(string, c);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(search_for_null_char)
{
	char	*string = "yolo";
	char	c = '\0';
	char	*ptr;
	char	*ft_ptr;

	ptr = strchr(string, c);
	ft_ptr = ft_strchr(string, c);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST
Suite	*ft_strchr_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRCHR");
	new = tcase_create("Result");
	tcase_add_test(new, simple_string);
	tcase_add_test(new, empty_string);
	tcase_add_test(new, search_for_null_char);
	suite_add_tcase(s, new);
	return (s);
}
