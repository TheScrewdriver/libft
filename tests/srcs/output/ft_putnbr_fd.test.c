/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:09:44 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/25 15:53:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple_nb1)
{
	const int	nb = 213;

	ft_putnbr_fd(nb, STDOUT_FILENO);
	printf("-->%d", nb);
	printf("\n");
}
END_TEST

START_TEST(negative1)
{
	const int	nb = -3213;

	ft_putnbr_fd(nb, STDOUT_FILENO);
	printf("-->%d", nb);
	printf("\n");
}
END_TEST

START_TEST(int_max)
{
	const int	nb = INT_MAX;

	ft_putnbr_fd(nb, STDOUT_FILENO);
	printf("-->%d", nb);
	printf("\n");
}
END_TEST

START_TEST(int_min)
{
	const int	nb = INT_MIN;

	ft_putnbr_fd(nb, STDOUT_FILENO);
	printf("-->%d", nb);
	printf("\n");
}
END_TEST

START_TEST(zero)
{
	const int	nb = 0;

	ft_putnbr_fd(nb, STDOUT_FILENO);
	printf("-->%d", nb);
	printf("\n");
}
END_TEST

Suite	*ft_putnbr_fd_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_PUTNBR_FD");
	new = tcase_create("Result");
	tcase_add_test(new, simple_nb1);
	tcase_add_test(new, negative1);
	tcase_add_test(new, int_max);
	tcase_add_test(new, int_min);
	tcase_add_test(new, zero);
	suite_add_tcase(s, new);
	return (s);
}
