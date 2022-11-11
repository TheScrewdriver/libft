/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:00:22 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/11 21:35:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# define OPEN_MAX FOPEN_MAX

typedef enum e_line_status
{
	INVALID_LINE,
	VALID_LINE
}	t_line_status;

size_t	index_of(const char *str, const char c);
char	*strnjoin(char *s1, const char *s2, const size_t n);

char	*get_next_line(int fd);

#endif
