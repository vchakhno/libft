/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ostream.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:27 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:42:03 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSTREAM_H
# define OSTREAM_H

# include "libft/arithmetic/fixed_types.h"
# include <stdbool.h>

/*
	Ostreams are an abstraction over output.
	They can be useful to generalize fd & str.
	It's like a nice way to wrap output side effects.
	It's pretty convenient for functions like printf, or array_print.
	Otherwise it's just weird and not that useful.
	Half the ostream types in this header are experimental,
	probably never needed and will be wiped out in the future.
*/

/******************************************************************************/
/* OSTREAM_BASE																  */
/******************************************************************************/

typedef t_u32			(*t_ostream_write)();
typedef struct s_ostream_base
{
	t_ostream_write	write;
	bool			ended;
}	t_ostream_base;

void	ft_ostream_base_init(t_ostream_base *stream, t_ostream_write write);

/******************************************************************************/
/* ANY_OSTREAM																  */
/******************************************************************************/

# ifndef OSTREAM_INTERNALS_H

typedef void			t_any_ostream;
typedef void			t_any_str_ostream;
typedef void			t_any_mem_ostream;

# else

typedef t_ostream_base	t_any_ostream;
typedef t_ostream_base	t_any_str_ostream;
typedef t_ostream_base	t_any_mem_ostream;

# endif

bool	ft_ostream_has_ended(t_any_ostream *stream);
t_u32	ft_ostream_write(t_any_ostream *stream, void *elems, t_u32 count);
bool	ft_ostream_write_byte(t_any_ostream *stream, t_u8 byte);

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

t_u32	ft_safe_write(int fd, void *ptr, t_u32 size);

void	ft_fd_ostream_init(t_fd_ostream *stream, int fd);
t_u32	ft_fd_ostream_write(t_fd_ostream *stream, char *str, t_u32 n);

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
t_u32	ft_fixed_str_ostream_write(t_fixed_str_ostream *stream,
			char *str, t_u32 n);

/******************************************************************************/
/* ARRAY_OSTREAM															  */
/******************************************************************************/

/*
	Writes to uuh, an array. Should probably be updated to t_any_array?
	It's like vector_push_multiple but without reallocation and in ostream form.
	A bit weird actually. I probably will never use the ostream form...
*/

typedef struct s_array_ostream
{
	t_ostream_base	base;
	void			*array;
	t_u32			elem_size;
	t_u32			capacity;
	t_u32			pos;
}	t_array_ostream;

void	ft_array_ostream_init(t_array_ostream *stream,
			void *array, t_u32 elem_size, t_u32 array_capacity);
t_u32	ft_array_ostream_write(t_array_ostream *stream,
			void *elems, t_u32 count);

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
	t_any_ostream	*destination;
}	t_buffered_ostream;

void	ft_buffered_ostream_init(t_buffered_ostream *stream,
			void *buffer, t_u32 buffer_size, t_any_ostream *destination);
t_u32	ft_buffered_ostream_write(t_buffered_ostream *stream,
			void *ptr, t_u32 size);
bool	ft_buffered_ostream_flush(t_buffered_ostream *stream);

#endif