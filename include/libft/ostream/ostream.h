/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ostream.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:27 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/08 03:25:57 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSTREAM_H
# define OSTREAM_H

# include "libft/fixed_types.h"
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
t_u32	ft_safe_read(int fd, void *ptr, t_u32 size);

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

/******************************************************************************/
/* PRINTING FIXED TYPES														  */
/******************************************************************************/

// Unsigned
bool	ft_u8_print(t_u8 value);
bool	ft_u8_println(t_u8 value);
bool	ft_u8_oprint(t_any_str_ostream *stream, t_u8 value);
bool	ft_u8_oprintln(t_any_str_ostream *stream, t_u8 value);

bool	ft_u16_print(t_u16 value);
bool	ft_u16_println(t_u16 value);
bool	ft_u16_oprint(t_any_str_ostream *stream, t_u16 value);
bool	ft_u16_oprintln(t_any_str_ostream *stream, t_u16 value);

bool	ft_u32_print(t_u32 value);
bool	ft_u32_println(t_u32 value);
bool	ft_u32_oprint(t_any_str_ostream *stream, t_u32 value);
bool	ft_u32_oprintln(t_any_str_ostream *stream, t_u32 value);

bool	ft_u64_print(t_u64 value);
bool	ft_u64_println(t_u64 value);
bool	ft_u64_oprint(t_any_str_ostream *stream, t_u64 value);
bool	ft_u64_oprintln(t_any_str_ostream *stream, t_u64 value);

// Signed
bool	ft_i8_print(t_i8 value);
bool	ft_i8_println(t_i8 value);
bool	ft_i8_oprint(t_any_str_ostream *stream, t_i8 value);
bool	ft_i8_oprintln(t_any_str_ostream *stream, t_i8 value);

bool	ft_i16_print(t_i16 value);
bool	ft_i16_println(t_i16 value);
bool	ft_i16_oprint(t_any_str_ostream *stream, t_i16 value);
bool	ft_i16_oprintln(t_any_str_ostream *stream, t_i16 value);

bool	ft_i32_print(t_i32 value);
bool	ft_i32_println(t_i32 value);
bool	ft_i32_oprint(t_any_str_ostream *stream, t_i32 value);
bool	ft_i32_oprintln(t_any_str_ostream *stream, t_i32 value);

bool	ft_i64_print(t_i64 value);
bool	ft_i64_println(t_i64 value);
bool	ft_i64_oprint(t_any_str_ostream *stream, t_i64 value);
bool	ft_i64_oprintln(t_any_str_ostream *stream, t_i64 value);

// Floating

// Prints a floating-point number in a format close to the scientific notation
//	- powers of 10 are multiples of 3
//	- 4 significant numbers maximum
//	- e0 isn't displayed
//	- right zeroes following a zero are ommited

bool	ft_f32_print(t_f32 value);
bool	ft_f32_println(t_f32 value);
bool	ft_f32_oprint(t_any_str_ostream *stream, t_f32 value);
bool	ft_f32_oprintln(t_any_str_ostream *stream, t_f32 value);

bool	ft_f64_print(t_f64 value);
bool	ft_f64_println(t_f64 value);
bool	ft_f64_oprint(t_any_str_ostream *stream, t_f64 value);
bool	ft_f64_oprintln(t_any_str_ostream *stream, t_f64 value);

bool	ft_f80_print(t_f80 value);
bool	ft_f80_println(t_f80 value);
bool	ft_f80_oprint(t_any_str_ostream *stream, t_f80 value);
bool	ft_f80_oprintln(t_any_str_ostream *stream, t_f80 value);

bool	ft_f128_print(t_f128 value);
bool	ft_f128_println(t_f128 value);
bool	ft_f128_oprint(t_any_str_ostream *stream, t_f128 value);
bool	ft_f128_oprintln(t_any_str_ostream *stream, t_f128 value);

// Complex
bool	ft_cf32_print(t_cf32 value);
bool	ft_cf32_println(t_cf32 value);
bool	ft_cf32_oprint(t_any_str_ostream *stream, t_cf32 value);
bool	ft_cf32_oprint(t_any_str_ostream *stream, t_cf32 value);

bool	ft_cf64_print(t_cf64 value);
bool	ft_cf64_println(t_cf64 value);
bool	ft_cf64_oprint(t_any_str_ostream *stream, t_cf64 value);
bool	ft_cf64_oprint(t_any_str_ostream *stream, t_cf64 value);

bool	ft_cf80_print(t_cf80 value);
bool	ft_cf80_println(t_cf80 value);
bool	ft_cf80_oprint(t_any_str_ostream *stream, t_cf80 value);
bool	ft_cf80_oprint(t_any_str_ostream *stream, t_cf80 value);

bool	ft_cf128_print(t_cf128 value);
bool	ft_cf128_println(t_cf128 value);
bool	ft_cf128_oprint(t_any_str_ostream *stream, t_cf128 value);
bool	ft_cf128_oprint(t_any_str_ostream *stream, t_cf128 value);

#endif