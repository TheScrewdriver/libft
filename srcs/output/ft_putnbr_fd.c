/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:06:37 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 22:07:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*strnb = ft_itoa(n);

	ft_putstr_fd(strnb, fd);
	free(strnb);
}