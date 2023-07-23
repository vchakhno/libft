/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ostream.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:27 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/23 17:53:16 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSTREAM_H
# define OSTREAM_H
# include "libft/io/ostream.h"
# undef OSTREAM_H
#else
# ifndef LIBFT_OSTREAM_H
#  define LIBFT_OSTREAM_H

#  include "libft/arithmetic/fixed_types.h"
#  include <stdbool.h>

/*
	Ostreams are an abstraction over output.
	They can be useful to generalize fd & str.
	They're a nice way to wrap output side effects.
	They're pretty convenient for functions like printf, or array_print.
	Otherwise it's just weird and not that useful.
	Half the ostream types in this header are experimental,
	probably never needed and will be wiped out in the future.
*/

/******************************************************************************/
/* OSTREAM_BASE																  */
/******************************************************************************/

typedef bool	(*t_ostream_write)();
typedef struct s_ostream_base
{
	t_ostream_write	write;
	bool			ended;
}	t_ostream_base;

void	ft_ostream_base_init(t_ostream_base *stream, t_ostream_write write);

/******************************************************************************/
/* ANY_OSTREAM																  */
/******************************************************************************/

typedef void	t_any_ostream;
typedef void	t_any_str_ostream;
typedef void	t_any_mem_ostream;

bool	ft_ostream_has_ended(t_any_ostream *any_stream);
bool	ft_ostream_write(t_any_ostream *any_stream, void *elems, t_u32 count);
bool	ft_ostream_write_byte(t_any_ostream *any_stream, t_u8 byte);

/******************************************************************************/
/* FD_OSTREAM																  */
/******************************************************************************/

/*
	The simplest of ostream types. Writes to a fd (unbuffered !).
	Maybe I should make it buffered by default?
*/

typedef struct s_fd_ostream
{
	t_ostream_base	base;
	int				fd;
}	t_fd_ostream;

void	ft_fd_ostream_init(t_fd_ostream *stream, int fd);
bool	ft_fd_ostream_write(t_fd_ostream *stream, char *str, t_u32 n);

/******************************************************************************/
/* FIXED_STR_OSTREAM														  */
/******************************************************************************/

/*
	Writes to a string buffer, terminated by \0.
	I'm not sure I'll ever get to use this one.
	It *seems* useful but in reality I might never need it.
*/

typedef struct s_fixed_str_ostream
{
	t_ostream_base	base;
	char			*dest;
	t_u32			pos;
	t_u32			size;
}	t_fixed_str_ostream;

void	ft_fixed_str_ostream_init(t_fixed_str_ostream *stream,
			char *dest, t_u32 size);
bool	ft_fixed_str_ostream_write(t_fixed_str_ostream *stream,
			char *str, t_u32 n);

/******************************************************************************/
/* BUFFERED_OSTREAM															  */
/******************************************************************************/

/*
	This one is really useful, but I'm afraid multiple will ever get in a row,
	which would just cause unnecessary copies. It's pretty dumb, because only
	files should get a buffer for now. So there are no n-buffered ostream.

	I should probably change the write so that if the data exceeds the buffer
	size, it is written directly to the underlying ostream instead of copying
	by chunks.
*/

typedef struct s_buffered_ostream
{
	t_ostream_base	base;
	void			*buffer;
	t_u32			buffer_size;
	t_u32			pos;
	t_any_ostream	*any_destination;
}	t_buffered_ostream;

void	ft_buffered_ostream_init(t_buffered_ostream *stream,
			void *buffer, t_u32 buffer_size, t_any_ostream *any_destination);
bool	ft_buffered_ostream_write(t_buffered_ostream *stream,
			void *ptr, t_u32 size);
bool	ft_buffered_ostream_flush(t_buffered_ostream *stream);

/******************************************************************************/
/* LINE BUFFERED_OSTREAM													  */
/******************************************************************************/

/*
	Used for live text output (including stdout and stderr).
*/

void	ft_line_buffered_ostream_init(t_buffered_ostream *stream,
			void *buffer, t_u32 buffer_size, t_any_ostream *any_destination);
bool	ft_line_buffered_ostream_write(t_buffered_ostream *stream,
			void *ptr, t_u32 size);
bool	ft_line_buffered_ostream_flush(t_buffered_ostream *stream);

# endif
#endif