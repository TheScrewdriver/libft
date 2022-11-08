/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:31:08 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/20 20:31:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(integer)
{
	int		content = 5;
	t_list	*ft_array;

	ft_array = ft_lstnew(&content);
	ck_assert_ptr_eq(ft_array->content, &content);
	ck_assert_ptr_eq(ft_array->next, NULL);
	free(ft_array);
}
END_TEST

START_TEST(string)
{
	char	*content = "test_string";
	t_list	*ft_array;

	ft_array = ft_lstnew(content);
	ck_assert_ptr_eq(ft_array->content, content);
	ck_assert_ptr_eq(ft_array->next, NULL);
	free(ft_array);
}
END_TEST

Suite	*ft_lstnew_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_LSTNEW");
	new = tcase_create("Result");
	tcase_add_test(new, integer);
	tcase_add_test(new, string);
	suite_add_tcase(s, new);
	return (s);
}
