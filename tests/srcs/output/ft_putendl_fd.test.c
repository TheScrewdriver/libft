/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:48:41 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 21:49:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

Suite	*ft_putendl_fd_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_PUTENDL_FD");
	new = tcase_create("Result");
	suite_add_tcase(s, new);
	return (s);
}
