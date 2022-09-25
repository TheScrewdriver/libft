/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:43:28 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/25 15:56:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const size_t	l_size = ft_strlen(little);
	size_t			i;
	char			*out;

	out = NULL;
	if (big[0] == '\0' && little[0] == '\0')
		out = (char *)big;
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (ft_strncmp(big + i, little, l_size) == 0)
		{
			out = (char *)(big + i);
			break ;
		}
		++i;
	}
	return (out);
}
