/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:37:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/26 12:51:50 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	taylor_approx(double x)
{
	size_t	k;
	double	t;
	double	s;
	double	z;

	x = -x;
	t = 0.0;
	s = 1;
	z = x;
	k = 1;
	while (k <= TAYLOR_ITERATIONS)
	{
		t += z * s / k;
		z *= x;
		s = -s;
		++k;
	}
	return (t);
}

double	ft_log(double x)
{
	int	power_adjust;

	if (x <= 0)
		return (0.0 / 0.0);// NaN
	power_adjust = 0;
	while (x > 1.0)
	{
		x /= EULER_CONST;
		power_adjust++;
	}
	while (x < .25)
	{
		x *= EULER_CONST;
		power_adjust--;
	}
	return (power_adjust + taylor_approx(x));
}
