/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:30:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/05/08 11:04:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rm_node(
	t_list **head,
	t_list **curr,
	t_list *prev,
	void (*del)(void *)
	)
{
	if (prev == NULL)
		*head = (*curr)->next;
	else
		prev->next = (*curr)->next;
	ft_lstdelone(*curr, del);
	*curr = *head;
	if (prev != NULL)
		*curr = prev->next;
}

void	ft_list_remove_if(
	t_list **head,
	void *ref,
	bool (*comp)(void *, void *),
	void (*del)(void *)
	)
{
	t_list	*curr;
	t_list	*prev;

	curr = *head;
	prev = NULL;
	while (curr != NULL)
	{
		if (comp(curr->content, ref) == true)
			rm_node(head, &curr, prev, del);
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}
