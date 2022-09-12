/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:03:56 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/12 16:02:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static bool	is_whitespace(const char c)
{
	return (c == SPACE || (FIRST_WHITESPACE <= c && c <= LAST_WHITESPACE));
}

int	ft_atoi(const char *nptr)
{
	long	nb;
	int8_t	sign;

	nb = 0;
	sign = 1;
	while (is_whitespace(*nptr) == true)
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	while ('0' <= *nptr && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr - '0');
		++nptr;
	}
	return (nb * sign);
}
