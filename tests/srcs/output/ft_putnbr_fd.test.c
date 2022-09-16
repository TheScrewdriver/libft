/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:09:44 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 22:10:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

Suite	*ft_putnbr_fd_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_PUTNBR_FD");
	new = tcase_create("Result");
	suite_add_tcase(s, new);
	return (s);
}
