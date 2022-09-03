/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:09:12 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/03 09:16:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static int	get_failed_from_suite(Suite *suite)
{
	int		not_failed;
	Suite	*s;
	SRunner	*runner;

	not_failed = 0;
	s = suite;
	runner = srunner_create(s);

	srunner_run_all(runner, CK_NORMAL);
	not_failed = srunner_ntests_failed(runner);
	srunner_free(runner);
	return (not_failed);
}

int	main(void)
{
	int		nbof_failed;
	size_t	i;
	Suite	*(*suite[NBOF_SUITE])(void) = {
		ft_strlen_suite,
		ft_isalpha_suite};

	nbof_failed = 0;
	i = 0;
	while (i < NBOF_SUITE)
	{
		nbof_failed += get_failed_from_suite(suite[i]());
		++i;
	}
	return (nbof_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}