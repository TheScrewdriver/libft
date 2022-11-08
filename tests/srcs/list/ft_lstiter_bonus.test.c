/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:26:37 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/21 11:32:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static void	function(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

START_TEST(null)
{
	t_list	*head;

	head = NULL;
	ft_lstiter(head, &function);
	ft_lstclear(&head, NULL);
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
	ft_lstiter(head, &function);
	ft_lstclear(&head, NULL);
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
	ft_lstiter(head, &function);
	ft_lstclear(&head, NULL);
}
END_TEST

Suite	*ft_lstiter_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_LSTITER");
	new = tcase_create("Result");
	tcase_add_test(new, null);
	tcase_add_test(new, destroy_end);
	tcase_add_test(new, null_function);
	suite_add_tcase(s, new);
	return (s);
}
