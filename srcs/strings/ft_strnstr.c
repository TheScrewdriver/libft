/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:43:28 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/06 18:56:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0'
			&& big[i + j] != '\0'
			&& little[j] == big[i + j]
			&& i + j < len)
			++j;
		if (little[j] == '\0')
			return ((char *)(big + i));
		++i;
	}
	if (big[0] == '\0' && little[0] == '\0')
		return (EMPTY_STRING);
	return (NULL);
}
