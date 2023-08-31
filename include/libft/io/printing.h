/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 07:33:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/08/18 00:09:05 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_H
# define PRINTING_H
# include "libft/io/printing.h"
# undef PRINTING_H
#else
# ifndef LIBFT_PRINTING_H
#  define LIBFT_PRINTING_H

#  include "libft/arithmetic/fixed_types.h"
#  include "libft/io/output.h"
#  include <stdbool.h>

/******************************************************************************/
/* PRINTING FIXED TYPES														  */
/******************************************************************************/

// Unsigned
bool	ft_u8_print(t_u8 value);
bool	ft_u8_println(t_u8 value);
bool	ft_u8_oprint(t_output *output, t_u8 value);
bool	ft_u8_oprintln(t_output *output, t_u8 value);

bool	ft_u16_print(t_u16 value);
bool	ft_u16_println(t_u16 value);
bool	ft_u16_oprint(t_output *output, t_u16 value);
bool	ft_u16_oprintln(t_output *output, t_u16 value);

bool	ft_u32_print(t_u32 value);
bool	ft_u32_println(t_u32 value);
bool	ft_u32_oprint(t_output *output, t_u32 value);
bool	ft_u32_oprintln(t_output *output, t_u32 value);

bool	ft_u64_print(t_u64 value);
bool	ft_u64_println(t_u64 value);
bool	ft_u64_oprint(t_output *output, t_u64 value);
bool	ft_u64_oprintln(t_output *output, t_u64 value);

// Signed
bool	ft_i8_print(t_i8 value);
bool	ft_i8_println(t_i8 value);
bool	ft_i8_oprint(t_output *output, t_i8 value);
bool	ft_i8_oprintln(t_output *output, t_i8 value);

bool	ft_i16_print(t_i16 value);
bool	ft_i16_println(t_i16 value);
bool	ft_i16_oprint(t_output *output, t_i16 value);
bool	ft_i16_oprintln(t_output *output, t_i16 value);

bool	ft_i32_print(t_i32 value);
bool	ft_i32_println(t_i32 value);
bool	ft_i32_oprint(t_output *output, t_i32 value);
bool	ft_i32_oprintln(t_output *output, t_i32 value);

bool	ft_i64_print(t_i64 value);
bool	ft_i64_println(t_i64 value);
bool	ft_i64_oprint(t_output *output, t_i64 value);
bool	ft_i64_oprintln(t_output *output, t_i64 value);

// Floating

// Prints a floating-point number in a format close to the scientific notation
//	- powers of 10 are multiples of 3
//	- 4 significant numbers maximum
//	- e0 isn't displayed
//	- right zeroes following a zero are ommited

bool	ft_f32_print(t_f32 value);
bool	ft_f32_println(t_f32 value);
bool	ft_f32_oprint(t_output *output, t_f32 value);
bool	ft_f32_oprintln(t_output *output, t_f32 value);

bool	ft_f64_print(t_f64 value);
bool	ft_f64_println(t_f64 value);
bool	ft_f64_oprint(t_output *output, t_f64 value);
bool	ft_f64_oprintln(t_output *output, t_f64 value);

bool	ft_f80_print(t_f80 value);
bool	ft_f80_println(t_f80 value);
bool	ft_f80_oprint(t_output *output, t_f80 value);
bool	ft_f80_oprintln(t_output *output, t_f80 value);

bool	ft_f128_print(t_f128 value);
bool	ft_f128_println(t_f128 value);
bool	ft_f128_oprint(t_output *output, t_f128 value);
bool	ft_f128_oprintln(t_output *output, t_f128 value);

// Complex
bool	ft_cf32_print(t_cf32 value);
bool	ft_cf32_println(t_cf32 value);
bool	ft_cf32_oprint(t_output *output, t_cf32 value);
bool	ft_cf32_oprintln(t_output *output, t_cf32 value);

bool	ft_cf64_print(t_cf64 value);
bool	ft_cf64_println(t_cf64 value);
bool	ft_cf64_oprint(t_output *output, t_cf64 value);
bool	ft_cf64_oprintln(t_output *output, t_cf64 value);

bool	ft_cf80_print(t_cf80 value);
bool	ft_cf80_println(t_cf80 value);
bool	ft_cf80_oprint(t_output *output, t_cf80 value);
bool	ft_cf80_oprintln(t_output *output, t_cf80 value);

bool	ft_cf128_print(t_cf128 value);
bool	ft_cf128_println(t_cf128 value);
bool	ft_cf128_oprint(t_output *output, t_cf128 value);
bool	ft_cf128_oprintln(t_output *output, t_cf128 value);

# endif
#endif