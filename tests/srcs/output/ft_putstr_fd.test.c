/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:08:03 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 17:08:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

Suite	*ft_putstr_fd_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_PUTSTR_FD");
	new = tcase_create("Result");
	suite_add_tcase(s, new);
	return (s);
}
