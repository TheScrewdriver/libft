/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:09:02 by rbroque           #+#    #+#             */
/*   Updated: 2022/08/31 12:09:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(test_simple1)
{
	ck_assert_int_eq(ft_strlen(""), 0);
}
END_TEST

START_TEST(test_simple2)
{
	ck_assert_int_eq(ft_strlen("Wouah"), 5);
}
END_TEST

Suite	*ft_strlen_suite(void)
{
	Suite	*s;
	TCase	*tc_core;

	s = suite_create("FT_STRLEN");
	tc_core = tcase_create("Result");

	tcase_add_test(tc_core, test_simple1);
	tcase_add_test(tc_core, test_simple2);
	suite_add_tcase(s, tc_core);

	return (s);
}
