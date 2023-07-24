/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 06:11:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 03:55:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# include "libft/io/io.h"
# undef IO_H
#else
# ifndef LIBFT_IO_H
#  define LIBFT_IO_H

#  include "libft/io/output.h"
#  include "libft/io/parsing/parsing.h"
#  include "libft/io/printf.h"
#  include "libft/io/printing.h"

# endif
#endif