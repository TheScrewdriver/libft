/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_in_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:48:05 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 07:48:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_c_in_str(const char *str, const char c)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		count += (*str == c);
		++str;
	}
	return (count);
}
