/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:04:27 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/12 19:22:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ft_strings.h"

# define SPACE ' '
# define FIRST_WHITESPACE 9 
# define LAST_WHITESPACE 13

int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
