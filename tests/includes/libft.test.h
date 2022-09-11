/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:03:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/11 12:59:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

# include "libft.h"
# include <check.h> 
# include <limits.h> 
# include <signal.h> 
# include <stdbool.h> 
# include <stdio.h> 
# include <stdint.h>
# include <bsd/string.h> 
# include <string.h> 
# include <ctype.h>

# define NBOF_SUITE 18

// ctype
Suite	*ft_isalpha_suite(void);
Suite	*ft_isupper_suite(void);
Suite	*ft_islower_suite(void);
Suite	*ft_isdigit_suite(void);
Suite	*ft_isalnum_suite(void);
Suite	*ft_isascii_suite(void);
Suite	*ft_isprint_suite(void);
Suite	*ft_toupper_suite(void);
Suite	*ft_tolower_suite(void);

// strings
Suite	*ft_strlen_suite(void);
Suite	*ft_memset_suite(void);
Suite	*ft_bzero_suite(void);
Suite	*ft_memcpy_suite(void);
Suite	*ft_memmove_suite(void);
Suite	*ft_strlcpy_suite(void);
Suite	*ft_strlcat_suite(void);
Suite	*ft_strchr_suite(void);
Suite	*ft_strrchr_suite(void);

#endif
