/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:25:12 by rbroque           #+#    #+#             */
/*   Updated: 2023/03/31 18:35:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*replace_str_safe(
	char *src,
	char *replace,
	const size_t index,
	const size_t delete_len
	)
{
	const size_t	src_len = ft_strlen(src);
	const size_t	replace_len = ft_strlen(replace);
	const size_t	total_len = src_len + replace_len - delete_len;
	char			*new;

	new = (char *)malloc((total_len + 1) * sizeof(char));
	if (new != NULL)
	{
		ft_strncpy(new, src, index);
		ft_strcpy(new + index, replace);
		ft_strcpy(new + index + replace_len, src + index + delete_len);
	}
	return (new);
}

char	*replace_str(
	char *src,
	char *replace,
	size_t index,
	size_t delete_len
	)
{
	const size_t	src_len = ft_strlen(src);
	const size_t	replace_len = ft_strlen(replace);

	if (index > src_len)
		index = src_len;
	if (delete_len > src_len + replace_len)
		delete_len = src_len + replace_len;
	if (delete_len > src_len - index)
		delete_len = src_len - index;
	return (replace_str_safe(src, replace, index, delete_len));
}
