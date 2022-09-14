/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:43:29 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/13 22:01:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src < dest && (uint8_t *)dest < (const uint8_t *)src + n)
	{
		i = 0;
		while (i < n)
		{
			((uint8_t *)dest)[n - i - 1] = ((const uint8_t *)src)[n - i - 1];
			++i;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
