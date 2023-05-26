/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_without_free.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:03:40 by rbroque           #+#    #+#             */
/*   Updated: 2023/05/26 23:07:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rm_node(
	t_list **head,
	t_list **curr,
	t_list *prev
	)
{
	if (prev == NULL)
		*head = (*curr)->next;
	else
		prev->next = (*curr)->next;
	*curr = *head;
	if (prev != NULL)
		*curr = prev->next;
}

void	ft_list_remove_if_without_free(
	t_list **head,
	void *ref,
	bool (*comp)(void *, void *)
	)
{
	t_list	*curr;
	t_list	*prev;

	curr = *head;
	prev = NULL;
	while (curr != NULL)
	{
		if (comp(curr->content, ref) == true)
			rm_node(head, &curr, prev);
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}
