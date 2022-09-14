/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:48:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/12 21:38:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.test.h"

START_TEST(simple)
{
	const size_t	nmemb = 5;
	const size_t	size = 4;
	void			*ptr;
	void			*ft_ptr;

	ptr = calloc(nmemb, size);
	ft_ptr = ft_calloc(nmemb, size);
	ck_assert_mem_eq(ptr, ft_ptr, size * nmemb);
	free(ptr);
	free(ft_ptr);
}
END_TEST

START_TEST(null_size)
{
	const size_t	nmemb = 5;
	const size_t	size = 0;
	void			*ptr;
	void			*ft_ptr;

	ptr = calloc(nmemb, size);
	ft_ptr = ft_calloc(nmemb, size);
	ck_assert_mem_eq(ptr, ft_ptr, size * nmemb);
	free(ptr);
	free(ft_ptr);
}
END_TEST

Suite	*ft_calloc_suite(void)
{
	Suite	*s;
	TCase	*new;

	s = suite_create("FT_CALLOC");
	new = tcase_create("Result");
	tcase_add_test(new, simple);
	tcase_add_test(new, null_size);

	suite_add_tcase(s, new);
	return (s);
}
