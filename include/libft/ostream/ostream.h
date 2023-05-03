/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ostream.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:27 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 12:53:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSTREAM_H
# define OSTREAM_H

# include "libft/str/str.h"
# include "libft/fixed_types.h"
# include <stdbool.h>

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

# else

typedef t_ostream_base	t_any_ostream;
typedef t_ostream_base	t_any_str_ostream;

# endif

bool	ft_ostream_has_ended(t_any_ostream *stream);
t_u32	ft_ostream_write(t_any_ostream *stream, void *elems, t_u32 count);
t_u32	ft_ostream_write_c_str(t_any_str_ostream *stream, char *c_str);
t_u32	ft_ostream_write_str(t_any_str_ostream *stream, t_any_str *str);

/******************************************************************************/
/* FD_OSTREAM																  */
/******************************************************************************/

typedef struct s_fd_ostream
{
	t_ostream_base	base;
	int				fd;
}	t_fd_ostream;

t_u32	ft_safe_write(int fd, void *ptr, t_u32 size);
t_u32	ft_safe_read(int fd, void *ptr, t_u32 size);

void	ft_fd_ostream_init(t_fd_ostream *stream, int fd);
t_u32	ft_fd_ostream_write(t_fd_ostream *stream, char *str, t_u32 n);

/******************************************************************************/
/* FIXED_STR_OSTREAM														  */
/******************************************************************************/

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