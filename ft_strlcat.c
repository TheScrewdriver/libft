/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:19:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/06 18:15:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	size_dest = ft_strlen(dst);
	const size_t	size_src = ft_strlen(src);

	if (dstsize <= size_dest)
		return (dstsize + size_src);
	ft_strlcpy(dst + size_dest, src, dstsize - size_dest);
	return (size_dest + size_src);
}
