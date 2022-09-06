/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:50:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/05 20:00:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

# include <limits.h>

# define FIRST_PRINTABLE 32
# define LAST_PRINTABLE 126

int	ft_isalpha(int c);
int	ft_islower(int c);
int	ft_isupper(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);

#endif
