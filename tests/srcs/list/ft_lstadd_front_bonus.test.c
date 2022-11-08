/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.test.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:28:58 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/20 20:42:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static void	free_list(t_list *head)
{
	if (head != NULL)
	{
		free_list(head->next);
		free(head);
	}
}

START_TEST(integer_content)
{
	int		content1 = 2;
	int		content2 = 123;
	t_list	*head;
	t_list	*new;

	head = ft_lstnew(&content1);
	new = ft_lstnew(&content2);
	ft_lstadd_front(&head, new);
	ck_assert_ptr_eq(head->content, &content2);
	free_list(head);
}
END_TEST

START_TEST(null_head)
{
	int		content = 123;
	t_list	*head;
	t_list	*new;

	head = NULL;
	new = ft_lstnew(&content);
	ft_lstadd_front(&head, new);
	ck_assert_ptr_eq(head->content, &content);
	free_list(head);
}
END_TEST

START_TEST(null_add)
{
	int		content = 42;
	t_list	*head;
	t_list	*new;

	head = ft_lstnew(&content);
	new = NULL;
	ft_lstadd_front(&head, new);
	ck_assert_ptr_eq(head->content, &content);
	free_list(head);
}
END_TEST

Suite	*ft_lstadd_front_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_LSTADD_FRONT");
	new = tcase_create("Result");
	tcase_add_test(new, integer_content);
	tcase_add_test(new, null_head);
	tcase_add_test(new, null_add);
	suite_add_tcase(s, new);
	return (s);
}
