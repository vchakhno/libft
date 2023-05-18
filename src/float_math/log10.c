/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log10.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:08:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/17 19:34:11 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/float_math.h"
#include "libft/bounds.h"

t_i8	ft_f32_log10(t_f32 value)
{
	t_i8	i;
	t_f32	clone;

	if (value == 0)
		return (0);
	i = 0;
	clone = 1;
	if (ft_f32_abs(value) < 1)
	{
		while (clone > ft_f32_abs(value))
		{
			clone /= 10;
			i--;
		}
		return (i);
	}
	while (clone < ft_f32_abs(value))
	{
		clone *= 10;
		i++;
	}
	return (i - (clone != ft_f32_abs(value)));
}

t_i16	ft_f64_log10(t_f64 value)
{
	t_i16	i;
	t_f64	clone;

	if (value == 0)
		return (0);
	i = 0;
	clone = 1;
	if (ft_f64_abs(value) < 1)
	{
		while (clone > ft_f64_abs(value))
		{
			clone /= 10;
			i--;
		}
		return (i);
	}
	while (clone < ft_f64_abs(value))
	{
		clone *= 10;
		i++;
	}
	return (i - (clone != ft_f64_abs(value)));
}

t_i16	ft_f80_log10(t_f80 value)
{
	t_i16	i;
	t_f80	clone;

	if (value == 0)
		return (0);
	i = 0;
	clone = 1;
	if (ft_f80_abs(value) < 1)
	{
		while (clone > ft_f80_abs(value))
		{
			clone /= 10;
			i--;
		}
		return (i);
	}
	while (clone < ft_f80_abs(value))
	{
		clone *= 10;
		i++;
	}
	return (i - (clone != ft_f80_abs(value)));
}

t_i16	ft_f128_log10(t_f128 value)
{
	t_i16	i;
	t_f128	clone;

	if (value == 0)
		return (0);
	i = 0;
	clone = 1;
	if (ft_f128_abs(value) < 1)
	{
		while (clone > ft_f128_abs(value))
		{
			clone /= 10;
			i--;
		}
		return (i);
	}
	while (clone < ft_f128_abs(value))
	{
		clone *= 10;
		i++;
	}
	return (i - (clone != ft_f128_abs(value)));
}
