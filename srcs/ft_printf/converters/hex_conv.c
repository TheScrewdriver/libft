/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:26:06 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/29 01:14:16 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*low_hex(unsigned long nb)
{
	return (itoa_base(nb, HEX));
}

char	*up_hex(unsigned long nb)
{
	return (toupper_str(low_hex(nb)));
}

char	*address(unsigned long address_value)
{
	void	*address = (void *)address_value;
	char	*output;

	if (address == NULL)
		output = ft_strdup(NIL_DEF);
	else
		output = itoa_base((unsigned long)address, HEX);
	return (output);
}
