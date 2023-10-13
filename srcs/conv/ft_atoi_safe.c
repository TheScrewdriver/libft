/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 06:49:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/13 07:18:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_whitespace(const char c)
{
	return (c == SPACE || (FIRST_WHITESPACE <= c && c <= LAST_WHITESPACE));
}

static bool	is_inbounds(
	const long nb,
	const long added_nb
	)
{
	const long	max_bound = (INT_MAX - added_nb) / 10;
	const long	min_bound = (INT_MIN - added_nb) / 10;

	return (nb >= min_bound && nb <= max_bound);
}

bool	ft_atoi_safe(
	int *const nb,
	const char *str
	)
{
	int		nb_tmp;
	size_t	i;

	nb_tmp = 0;
	while (is_whitespace(*str) == true)
		++str;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		++i;
	while (ft_isdigit(str[i]) == true)
	{
		if (is_inbounds(nb_tmp, str[i] - '0') == false)
			return (false);
		nb_tmp = nb_tmp * 10 + (str[i] - '0');
		++i;
	}
	*nb = nb_tmp;
	if (str[0] == '-')
		*nb = -nb_tmp;
	return (true);
}
