/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:30:49 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/14 17:39:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	len1 = ft_strlen(s1);
	const size_t	len2 = ft_strlen(s2);
	char			*new;

	new = (char *)malloc((len1 + len2 + 1) + sizeof(char));
	if (new != NULL)
	{
		ft_strcpy(new, (char *)s1);
		ft_strcpy(new + len1, (char *)s2);
	}
	return (new);
}
