/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:10:09 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/22 11:19:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static void	*add(void *ptr)
{
	int	*new;

	new = (int *)malloc(sizeof(int));
	*new = 0;
	if (ptr != NULL)
		*new = *((int *)(ptr)) + 1;
	return (new);
}

START_TEST(null)
{
	t_list	*head;
	t_list	*new;

	head = NULL;
	new = ft_lstmap(head, &add, free);
	ck_assert_ptr_eq(NULL, NULL);
	ft_lstclear(&head, NULL);
	ft_lstclear(&new, NULL);
}
END_TEST

START_TEST(numbers)
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
	t_list	*new0;
	t_list	*new1;
	t_list	*new2;
	t_list	*new3;
	t_list	*new4;
	t_list	*new5;
	t_list	*new6;
	t_list	*new7;
	t_list	*new8;
	t_list	*new9;
	int		n0 = 0;
	int		n1 = 1;
	int		n2 = 2;
	int		n3 = 3;
	int		n4 = 4;
	int		n5 = 5;
	int		n6 = 6;
	int		n7 = 7;
	int		n8 = 8;
	int		n9 = 9;

	head0 = ft_lstnew(&n0);
	head1 = ft_lstnew(&n1);
	head2 = ft_lstnew(&n2);
	head3 = ft_lstnew(&n3);
	head4 = ft_lstnew(&n4);
	head5 = ft_lstnew(&n5);
	head6 = ft_lstnew(&n6);
	head7 = ft_lstnew(&n7);
	head8 = ft_lstnew(&n8);
	head9 = ft_lstnew(&n9);

	ft_lstadd_back(&head0, head1);
	ft_lstadd_back(&head0, head2);
	ft_lstadd_back(&head0, head3);
	ft_lstadd_back(&head0, head4);
	ft_lstadd_back(&head0, head5);
	ft_lstadd_back(&head0, head6);
	ft_lstadd_back(&head0, head7);
	ft_lstadd_back(&head0, head8);
	ft_lstadd_back(&head0, head9);

	new0 = ft_lstmap(head0, &add, NULL);
	new1 = new0->next;
	new2 = new1->next;
	new3 = new2->next;
	new4 = new3->next;
	new5 = new4->next;
	new6 = new5->next;
	new7 = new6->next;
	new8 = new7->next;
	new9 = new8->next;
	ck_assert_int_eq(*((int *)(new0->content)), 1);
	ck_assert_int_eq(*((int *)(new1->content)), 2);
	ck_assert_int_eq(*((int *)(new2->content)), 3);
	ck_assert_int_eq(*((int *)(new3->content)), 4);
	ck_assert_int_eq(*((int *)(new4->content)), 5);
	ck_assert_int_eq(*((int *)(new5->content)), 6);
	ck_assert_int_eq(*((int *)(new6->content)), 7);
	ck_assert_int_eq(*((int *)(new7->content)), 8);
	ck_assert_int_eq(*((int *)(new8->content)), 9);
	ck_assert_int_eq(*((int *)(new9->content)), 10);
	ft_lstclear(&head0, NULL);
	ft_lstclear(&new0, free);
}
END_TEST

START_TEST(null_function)
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
	t_list	*new0;
	t_list	*new1;
	t_list	*new2;
	t_list	*new3;
	t_list	*new4;
	t_list	*new5;
	t_list	*new6;
	t_list	*new7;
	t_list	*new8;
	t_list	*new9;
	int		n0 = 0;
	int		n1 = 1;
	int		n2 = 2;
	int		n3 = 3;
	int		n4 = 4;
	int		n5 = 5;
	int		n6 = 6;
	int		n7 = 7;
	int		n8 = 8;
	int		n9 = 9;

	head0 = ft_lstnew(&n0);
	head1 = ft_lstnew(&n1);
	head2 = ft_lstnew(&n2);
	head3 = ft_lstnew(&n3);
	head4 = ft_lstnew(&n4);
	head5 = ft_lstnew(&n5);
	head6 = ft_lstnew(&n6);
	head7 = ft_lstnew(&n7);
	head8 = ft_lstnew(&n8);
	head9 = ft_lstnew(&n9);

	ft_lstadd_back(&head0, head1);
	ft_lstadd_back(&head0, head2);
	ft_lstadd_back(&head0, head3);
	ft_lstadd_back(&head0, head4);
	ft_lstadd_back(&head0, head5);
	ft_lstadd_back(&head0, head6);
	ft_lstadd_back(&head0, head7);
	ft_lstadd_back(&head0, head8);
	ft_lstadd_back(&head0, head9);

	new0 = ft_lstmap(head0, NULL, NULL);
	new1 = new0->next;
	new2 = new1->next;
	new3 = new2->next;
	new4 = new3->next;
	new5 = new4->next;
	new6 = new5->next;
	new7 = new6->next;
	new8 = new7->next;
	new9 = new8->next;
	ck_assert_int_eq(*((int *)(new0->content)), 0);
	ck_assert_int_eq(*((int *)(new1->content)), 1);
	ck_assert_int_eq(*((int *)(new2->content)), 2);
	ck_assert_int_eq(*((int *)(new3->content)), 3);
	ck_assert_int_eq(*((int *)(new4->content)), 4);
	ck_assert_int_eq(*((int *)(new5->content)), 5);
	ck_assert_int_eq(*((int *)(new6->content)), 6);
	ck_assert_int_eq(*((int *)(new7->content)), 7);
	ck_assert_int_eq(*((int *)(new8->content)), 8);
	ck_assert_int_eq(*((int *)(new9->content)), 9);
	ft_lstclear(&head0, NULL);
	ft_lstclear(&new0, NULL);
}
END_TEST

Suite	*ft_lstmap_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_LSTMAP");
	new = tcase_create("Result");
	tcase_add_test(new, null);
	tcase_add_test(new, numbers);
	tcase_add_test(new, null_function);
	suite_add_tcase(s, new);
	return (s);
}
