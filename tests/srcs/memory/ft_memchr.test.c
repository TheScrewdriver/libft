/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:01:30 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/12 11:18:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple_string)
{
	char	*string = "hello my name is Neo";
	int		c = 'l';
	size_t	size = 6;
	char	*ptr;
	char	*ft_ptr;

	ptr = memchr(string, c, size);
	ft_ptr = ft_memchr(string, c, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(empty_string)
{
	char	*string = "";
	char	c = 'l';
	size_t	size = 1;
	char	*ptr;
	char	*ft_ptr;

	ptr = memchr(string, c, size);
	ft_ptr = ft_memchr(string, c, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(null_size)
{
	char	*string = "123ssadlasdlasdllllllsad";
	char	c = 'l';
	size_t	size = 0;
	char	*ptr;
	char	*ft_ptr;

	ptr = memchr(string, c, size);
	ft_ptr = ft_memchr(string, c, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST

START_TEST(search_for_null_char)
{
	char	*string = "yolo";
	char	c = '\0';
	size_t	size = 5;
	char	*ptr;
	char	*ft_ptr;

	ptr = memchr(string, c, size);
	ft_ptr = ft_memchr(string, c, size);
	ck_assert_ptr_eq(ptr, ft_ptr);
}
END_TEST
Suite	*ft_memchr_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_MEMCHR");
	new = tcase_create("Result");
	tcase_add_test(new, simple_string);
	tcase_add_test(new, empty_string);
	tcase_add_test(new, null_size);
	tcase_add_test(new, search_for_null_char);
	suite_add_tcase(s, new);
	return (s);
}
