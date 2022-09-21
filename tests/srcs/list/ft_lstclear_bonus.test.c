/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:04:37 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/21 11:09:13 by rbroque          ###   ########.fr       */
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
	ft_lstclear(&head, &free_content1);
	ck_assert_ptr_eq(head, NULL);
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
	ft_lstclear(&head, &free_content1);
	ck_assert_ptr_eq(head, NULL);
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
	ft_lstclear(&head, NULL);
	free(str);
	ck_assert_ptr_eq(head, NULL);
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
	ft_lstclear(&head0, NULL);
	ck_assert_ptr_eq(head0, NULL);
}
END_TEST
Suite	*ft_lstclear_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_LSTCLEAR");
	new = tcase_create("Result");
	tcase_add_test(new, null);
	tcase_add_test(new, destroy_end);
	tcase_add_test(new, null_function);
	tcase_add_test(new, multiple);
	suite_add_tcase(s, new);
	return (s);
}
