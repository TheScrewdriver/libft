/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:08:56 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 09:24:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	const size_t	len = ft_strlen(s);
	size_t			i;
	char			*new;

	new = (char *)malloc((len + 1) * sizeof(char));
	if (new != NULL)
	{
		i = 0;
		while (i < len)
		{
			new[i] = f(i, s[i]);
			++i;
		}
		new[len] = '\0';
	}
	return (new);
}
