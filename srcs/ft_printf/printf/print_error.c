/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:19:05 by rbroque           #+#    #+#             */
/*   Updated: 2023/05/28 13:19:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_error(const char *format, ...)
{
	va_list	arg;

	va_start(arg, format);
	ft_vdprintf(STDERR_FILENO, format, arg);
	va_end(arg);
}
