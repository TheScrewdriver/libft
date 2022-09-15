/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 00:50:22 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 01:21:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(positive1)
{
	const int	nb = 213;
	const char	*expected_str = "213";
	char		*new;

	new = ft_itoa(nb);
	ck_assert_str_eq(new, expected_str);
	free(new);
}
END_TEST

START_TEST(positive2)
{
	const int	nb = 21123309;
	const char	*expected_str = "21123309";
	char		*new;

	new = ft_itoa(nb);
	ck_assert_str_eq(new, expected_str);
	free(new);
}
END_TEST

START_TEST(zero)
{
	const int	nb = 0;
	const char	*expected_str = "0";
	char		*new;

	new = ft_itoa(nb);
	ck_assert_str_eq(new, expected_str);
	free(new);
}
END_TEST

START_TEST(negative)
{
	const int	nb = -42;
	const char	*expected_str = "-42";
	char		*new;

	new = ft_itoa(nb);
	ck_assert_str_eq(new, expected_str);
	free(new);
}
END_TEST

START_TEST(int_min)
{
	const int	nb = INT_MIN;
	const char	*expected_str = "-2147483648";
	char		*new;

	new = ft_itoa(nb);
	ck_assert_str_eq(new, expected_str);
	free(new);
}
END_TEST

START_TEST(int_max)
{
	const int	nb = INT_MAX;
	const char	*expected_str = "2147483647";
	char		*new;

	new = ft_itoa(nb);
	ck_assert_str_eq(new, expected_str);
	free(new);
}
END_TEST
Suite	*ft_itoa_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_ITOA");
	new = tcase_create("Result");

	tcase_add_test(new, positive1);
	tcase_add_test(new, positive2);
	tcase_add_test(new, zero);
	tcase_add_test(new, negative);
	tcase_add_test(new, int_min);
	tcase_add_test(new, int_max);
	suite_add_tcase(s, new);

	return (s);
}
