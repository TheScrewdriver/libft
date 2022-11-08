/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.test.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:47:27 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/21 00:30:56 by rbroque          ###   ########.fr       */
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

START_TEST(null_start)
{
	int		content1 = 2;
	t_list	*head;
	t_list	*last;

	head = NULL;
	last = ft_lstnew(&content1);
	ft_lstadd_back(&head, last);
	ck_assert_ptr_eq(ft_lstlast(head), last);
	free_list(head);
}
END_TEST

START_TEST(null_null)
{
	t_list	*head;
	t_list	*last;

	head = NULL;
	last = NULL;
	ft_lstadd_back(&head, last);
	ck_assert_ptr_eq(ft_lstlast(head), head);
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

	ft_lstadd_back(&head0, head1);
	ft_lstadd_back(&head0, head2);
	ft_lstadd_back(&head0, head3);
	ft_lstadd_back(&head0, head4);
	ft_lstadd_back(&head0, head5);
	ft_lstadd_back(&head0, head6);
	ft_lstadd_back(&head0, head7);
	ft_lstadd_back(&head0, head8);
	ft_lstadd_back(&head0, head9);
	ck_assert_ptr_eq(ft_lstlast(head0), head9);
	free_list(head0);
}
END_TEST

Suite	*ft_lstadd_back_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_LSTADD_BACK");
	new = tcase_create("Result");
	tcase_add_test(new, null_start);
	tcase_add_test(new, null_null);
	tcase_add_test(new, multiple);
	suite_add_tcase(s, new);
	return (s);
}
