/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:59:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/21 11:02:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst != NULL && *lst != NULL)
	{
		ft_lstclear(&(*lst)->next, del);
		if (del != NULL)
			del((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
}
