/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:47:45 by rbroque           #+#    #+#             */
/*   Updated: 2023/05/29 18:25:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp_lst;

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			tmp_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp_lst;
		}
	}
}
