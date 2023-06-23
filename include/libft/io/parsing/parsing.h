/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 07:40:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/23 04:06:25 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "libft/io/parsing/parsing.h"
# undef PARSING_H
#else
# ifndef LIBFT_PARSING_H
#  define LIBFT_PARSING_H

#  include "libft/arithmetic/fixed_types.h"

t_u32	ft_safe_read(int fd, void *ptr, t_u32 size);

# endif
#endif