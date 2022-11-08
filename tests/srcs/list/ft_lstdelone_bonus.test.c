/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:35:26 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/21 11:06:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static void	free_content1(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

START_TEST(null)
{
	t_list	*head;

	head = NULL;
	ft_lstdelone(head, &free_content1);
}
END_TEST

START_TEST(destroy_end)
{
	char	*str;
	t_list	*head;
	t_list	*last;

	str = ft_strdup("lolilou");
	head = ft_lstnew(NULL);
	last = ft_lstnew(str);
	ft_lstadd_back(&head, last);
	ft_lstdelone(last, &free_content1);
	ft_lstdelone(head, &free_content1);
}
END_TEST

START_TEST(null_function)
{
	char	*str;
	t_list	*head;
	t_list	*last;

	str = ft_strdup("lolilou");
	head = ft_lstnew(NULL);
	last = ft_lstnew(str);
	ft_lstadd_back(&head, last);
	ft_lstdelone(last, NULL);
	ft_lstdelone(head, NULL);
	free(str);
}
END_TEST

Suite	*ft_lstdelone_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_LSTDELONE");
	new = tcase_create("Result");
	tcase_add_test(new, null);
	tcase_add_test(new, destroy_end);
	tcase_add_test(new, null_function);
	suite_add_tcase(s, new);
	return (s);
}
