/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:23:27 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/21 11:25:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL)
	{
		if (f != NULL)
			f(lst->content);
		ft_lstiter(lst->next, f);
	}
}
