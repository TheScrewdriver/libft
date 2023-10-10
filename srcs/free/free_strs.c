/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:40:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/10 08:25:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_strs(char **const strs)
{
	size_t	i;

	if (strs != NULL)
	{
		i = 0;
		while (strs[i] != NULL)
		{
			free((void *)strs[i]);
			++i;
		}
		free(strs);
	}
}
