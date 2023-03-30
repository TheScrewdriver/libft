/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:49:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/03/30 11:50:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_in_str(const char *str, const char c)
{
	if (str == NULL)
		return (false);
	return (ft_strchr(str, c) != NULL);
}
