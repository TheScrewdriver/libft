/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:53:45 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/08 15:27:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static int	are_array_same(void *array1, void *array2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && (((uint8_t *)array1)[i] - ((uint8_t *)array2)[i] == 0))
		++i;
	return (i == size);
}

START_TEST(empty_array)
{
	const size_t	size = 5;
	const int		content = 4;
	int				array[5];
	int				ft_array[5];

	memset(array, content, size * sizeof(int));
	ft_memset(ft_array, content, size * sizeof(int));
	ck_assert_int_eq(are_array_same(array, array, size), 1);
}
END_TEST

Suite	*ft_memset_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_MEMSET");
	new = tcase_create("Result");
	tcase_add_test(new, empty_array);
	suite_add_tcase(s, new);
	return (s);
}
