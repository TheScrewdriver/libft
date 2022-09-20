/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:41:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/20 23:17:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	while (lst != NULL)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}
