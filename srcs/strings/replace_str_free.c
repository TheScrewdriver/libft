/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_str_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:44:42 by rbroque           #+#    #+#             */
/*   Updated: 2023/04/10 16:00:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*replace_str_free(
	char *src,
	const char *replace,
	size_t index,
	size_t delete_len
	)
{
	char *const	new_str = replace_str(src, replace, index, delete_len);

	free(src);
	return (new_str);
}
