/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_suffix_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:22:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/06 09:23:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_suffix_valid(const char *const str, const char *const suffix)
{
	const size_t	len_str = ft_strlen(str);
	const size_t	len_suffix = ft_strlen(suffix);
	size_t			offset;

	if (len_str < len_suffix)
		return (false);
	offset = len_str - len_suffix;
	return (streq(str + offset, suffix));
}