/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:09:12 by rbroque           #+#    #+#             */
/*   Updated: 2022/08/31 12:09:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

int	main(void)
{
	int		not_failed;
	Suite	*s;
	SRunner	*runner;

	not_failed = 0;
	s = ft_strlen_suite();
	runner = srunner_create(s);
	
	srunner_run_all(runner, CK_NORMAL);
	not_failed = srunner_ntests_failed(runner);
	srunner_free(runner);
	return (not_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
