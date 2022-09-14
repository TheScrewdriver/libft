/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:32:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/14 19:01:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*trim;

	while (*s1 != '\0' && ft_strchr(set, *s1) != NULL)
		++s1;
	len = ft_strlen(s1);
	if (len > 0)
	{
		while (len > 0 && ft_strchr(set, s1[len - 1]) != NULL)
			--len;
	}
	else
		len = 1;
	trim = ft_strndup(s1, len);
	trim[len] = '\0';
	return (trim);
}
