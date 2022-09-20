/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:03:31 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/20 22:13:13 by rbroque          ###   ########.fr       */
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

START_TEST(only_one)
{
	int		content1 = 2;
	t_list	*head;

	head = ft_lstnew(&content1);
	ck_assert_int_eq(ft_lstsize(head), 1);
	free_list(head);
}
END_TEST

START_TEST(null)
{
	t_list	*head;

	head = NULL;
	ck_assert_int_eq(ft_lstsize(head), 0);
}
END_TEST

START_TEST(multiple)
{
	t_list	*head0;
	t_list	*head1;
	t_list	*head2;
	t_list	*head3;
	t_list	*head4;
	t_list	*head5;
	t_list	*head6;
	t_list	*head7;
	t_list	*head8;
	t_list	*head9;

	head0 = ft_lstnew(NULL);
	head1 = ft_lstnew(NULL);
	head2 = ft_lstnew(NULL);
	head3 = ft_lstnew(NULL);
	head4 = ft_lstnew(NULL);
	head5 = ft_lstnew(NULL);
	head6 = ft_lstnew(NULL);
	head7 = ft_lstnew(NULL);
	head8 = ft_lstnew(NULL);
	head9 = ft_lstnew(NULL);

	ft_lstadd_front(&head0, head1);
	ft_lstadd_front(&head0, head2);
	ft_lstadd_front(&head0, head3);
	ft_lstadd_front(&head0, head4);
	ft_lstadd_front(&head0, head5);
	ft_lstadd_front(&head0, head6);
	ft_lstadd_front(&head0, head7);
	ft_lstadd_front(&head0, head8);
	ft_lstadd_front(&head0, head9);
	ck_assert_int_eq(ft_lstsize(head0), 10);
	free_list(head0);
}
END_TEST

Suite	*ft_lstsize_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_LSTSIZE");
	new = tcase_create("Result");
	tcase_add_test(new, only_one);
	tcase_add_test(new, null);
	tcase_add_test(new, multiple);
	suite_add_tcase(s, new);
	return (s);
}
