/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:51:13 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/14 18:56:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple_string)
{
	char	*string = "hello my name is Neo";
	size_t	size = 6;
	char	*ptr;
	char	*ft_ptr;

	ptr = strndup(string, size);
	ft_ptr = ft_strndup(string, size);
	ck_assert_str_eq(ptr, ft_ptr);
	free(ptr);
	free(ft_ptr);
}
END_TEST

START_TEST(empty_string)
{
	char	*string = "";
	size_t	size = 1;
	char	*ptr;
	char	*ft_ptr;

	ptr = strndup(string, size);
	ft_ptr = ft_strndup(string, size);
	ck_assert_str_eq(ptr, ft_ptr);
	free(ptr);
	free(ft_ptr);
}
END_TEST

Suite	*ft_strndup_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRNDUP");
	new = tcase_create("Result");
	tcase_add_test(new, simple_string);
	tcase_add_test(new, empty_string);

	suite_add_tcase(s, new);
	return (s);
}
