/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:30:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 17:05:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

Suite	*ft_putchar_fd_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_PUTCHAR_FD");
	new = tcase_create("Result");
	suite_add_tcase(s, new);
	return (s);
}
