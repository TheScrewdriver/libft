/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:03:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/04 09:53:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

# include "libft.h"
# include <check.h> 
# include <limits.h> 
# include <stdio.h> 
# include <string.h> 
# include <ctype.h>

# define NBOF_SUITE 5

Suite	*ft_strlen_suite(void);
Suite	*ft_isalpha_suite(void);
Suite	*ft_isupper_suite(void);
Suite	*ft_islower_suite(void);
Suite	*ft_isdigit_suite(void);

#endif
