/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:45:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/04/24 22:46:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(char *s1, const char *s2, const size_t len)
{
	char *const	new = ft_strnjoin(s1, s2, len);

	free(s1);
	return (new);
}
