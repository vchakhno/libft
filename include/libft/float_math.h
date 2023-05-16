/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:43:50 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/08 01:32:53 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_MATH_H
# define FLOAT_MATH_H

# include "libft/fixed_types.h"

t_f32	ft_f32_trunc(t_f32 value);
t_f32	ft_f32_fract(t_f32 value);
t_i8	ft_f32_log10(t_f32 value);
t_f32	ft_f32_10pow(t_i8 value);
t_f32	ft_f32_mod(t_f32 value, t_f32 mod);

t_f64	ft_f64_trunc(t_f64 value);
t_f64	ft_f64_fract(t_f64 value);
t_i16	ft_f64_log10(t_f64 value);
t_f64	ft_f64_10pow(t_i16 value);
t_f64	ft_f64_mod(t_f64 value, t_f64 mod);

t_f80	ft_f80_trunc(t_f80 value);
t_f80	ft_f80_fract(t_f80 value);
t_i16	ft_f80_log10(t_f80 value);
t_f80	ft_f80_10pow(t_i16 value);
t_f80	ft_f80_mod(t_f80 value, t_f80 mod);

t_f128	ft_f128_trunc(t_f128 value);
t_f128	ft_f128_fract(t_f128 value);
t_i16	ft_f128_log10(t_f128 value);
t_f128	ft_f128_10pow(t_i16 value);
t_f128	ft_f128_mod(t_f128 value, t_f128 mod);

#endif