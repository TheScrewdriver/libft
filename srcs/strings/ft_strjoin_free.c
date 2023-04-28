/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:25:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/04/28 11:26:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char *const	tmp = s1;
	char *const	join = ft_strjoin(s1, s2);

	free(tmp);
	return (join);
}
