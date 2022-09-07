/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:53:45 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/07 19:19:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

static int	are_array_same(void *array1, void *array2, size_t size)
{
	size_t	i;
	
	i = 0;
	while (i < size && (((int *)array1)[i] - ((int *)array2)[i] == 0))
		++i;
	printf("i ----------------> %zu\n", i);
	printf("array[%zu] ----------------> %zu\n", i, ((int *)array1)[i]);
	printf("ft_array[%zu] ----------------> %zu\n", i, ((int *)array2)[i]);
	return (i == size);
}

START_TEST(empty_array)
{
	const size_t	size = 5;
	const int		content = 4;
	void			*array[5];
	void			*ft_array[5];

	memset(array, content, size);
	ft_memset(ft_array, content, size);
	ck_assert_int_eq(are_array_same(array, ft_array, size) == 1, 1);
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
