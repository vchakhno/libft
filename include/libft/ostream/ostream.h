/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ostream.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:27 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 15:45:56 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSTREAM_H
# define OSTREAM_H

# ifndef OSTREAM_INTERNAL_TYPES_H
#  include "ostream_types.h"
# endif

# include "libft/str/str.h"
# include <stddef.h>
# include <stdbool.h>

size_t	ft_safe_write(int fd, void *ptr, size_t size);
size_t	ft_safe_read(int fd, void *ptr, size_t size);

void	ft_ostream_base_init(t_ostream_base *stream, t_ostream_write write);

bool	ft_ostream_has_ended(t_any_ostream *stream);
size_t	ft_ostream_write(t_any_ostream *stream, void *elems, size_t count);
size_t	ft_ostream_write_c_str(t_any_str_ostream *stream, char *c_str);
size_t	ft_ostream_write_str(t_any_str_ostream *stream, t_any_str *str);

void	ft_fd_ostream_init(t_fd_ostream *stream, int fd);
size_t	ft_fd_ostream_write(t_fd_ostream *stream, char *str, size_t n);

void	ft_fixed_str_ostream_init(t_fixed_str_ostream *stream,
			char *dest, size_t size);
size_t	ft_fixed_str_ostream_write(t_fixed_str_ostream *stream,
			char *str, size_t n);

void	ft_array_ostream_init(t_array_ostream *stream,
			void *array, size_t elem_size, size_t array_capacity);
size_t	ft_array_ostream_write(t_array_ostream *stream,
			void *elems, size_t count);

void	ft_buffered_ostream_init(t_buffered_ostream *stream,
			void *buffer, size_t buffer_size, t_any_ostream *destination);
size_t	ft_buffered_ostream_write(t_buffered_ostream *stream,
			void *ptr, size_t size);
bool	ft_buffered_ostream_flush(t_buffered_ostream *stream);

#endif