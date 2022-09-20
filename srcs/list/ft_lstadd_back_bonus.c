/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:39:07 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/21 00:30:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			curr = *lst;
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = new;
		}
		else
			*lst = new;
	}
}
