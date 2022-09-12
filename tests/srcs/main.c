/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:09:12 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/12 16:47:39 by rbroque          ###   ########.fr       */
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
	int				nbof_failed;
	size_t			i;
	static Suite	*(*suite[NBOF_SUITE])(void) = {
		ft_strlen_suite,
		ft_memset_suite,
		ft_bzero_suite,
		ft_memcpy_suite,
		ft_memmove_suite,
		ft_strlcpy_suite,
		ft_strlcat_suite,
		ft_strchr_suite,
		ft_strrchr_suite,
		ft_strncmp_suite,
		ft_memchr_suite,
		ft_memcmp_suite,
		ft_strnstr_suite,
		ft_isalpha_suite,
		ft_isupper_suite,
		ft_islower_suite,
		ft_isdigit_suite,
		ft_isalnum_suite,
		ft_isascii_suite,
		ft_isprint_suite,
		ft_toupper_suite,
		ft_tolower_suite,
		ft_atoi_suite,
		ft_calloc_suite};

	nbof_failed = 0;
	i = 0;
	while (i < NBOF_SUITE)
	{
		nbof_failed += get_failed_from_suite(suite[i]());
		++i;
	}
	return (nbof_failed != 0);
}
