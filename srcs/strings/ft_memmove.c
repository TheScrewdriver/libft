/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:43:29 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/09 11:49:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

static size_t	get_min(size_t size1, size_t size2)
{
	if (size1 > size2)
		return (size2);
	return (size1);
}

#include <stdio.h>
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	uint8_t	buffer[BUFFER_SIZE];
	size_t	i;

	ft_bzero(buffer, BUFFER_SIZE);
	i = 0;
	while (i < n)
	{
		ft_memcpy(buffer, src + i, BUFFER_SIZE);
		printf("----------->%zu\n", get_min(n - i, BUFFER_SIZE));
		ft_memcpy(dest + i, buffer, get_min(n - i, BUFFER_SIZE));
		ft_bzero(buffer, BUFFER_SIZE);
		i += BUFFER_SIZE;
	}
	printf("\n\n");
	return (dest);
}

/*
Start stop

Start

StStarttop
*/
