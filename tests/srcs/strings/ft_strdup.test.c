/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:49:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/12 23:25:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple_string)
{
	char	*string = "hello my name is Neo";
	char	*ptr;
	char	*ft_ptr;

	ptr = strdup(string);
	ft_ptr = ft_strdup(string);
	ck_assert_str_eq(ptr, ft_ptr);
	free(ptr);
	free(ft_ptr);
}
END_TEST

START_TEST(empty_string)
{
	char	*string = "";
	char	*ptr;
	char	*ft_ptr;

	ptr = strdup(string);
	ft_ptr = ft_strdup(string);
	ck_assert_str_eq(ptr, ft_ptr);
	free(ptr);
	free(ft_ptr);
}
END_TEST

Suite	*ft_strdup_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_STRDUP");
	new = tcase_create("Result");
	tcase_add_test(new, simple_string);
	tcase_add_test(new, empty_string);

	suite_add_tcase(s, new);
	return (s);
}
