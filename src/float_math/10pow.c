/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10pow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:05:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/08 03:39:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/float_math.h"

t_f32	ft_f32_10pow(t_i8 pow)
{
	t_f32	value;

	value = 1;
	if (pow < 0)
	{
		while (pow)
		{
			value /= 10;
			pow++;
		}
	}
	else
	{
		while (pow)
		{
			value *= 10;
			pow--;
		}
	}
	return (value);
}

t_f64	ft_f64_10pow(t_i16 pow)
{
	t_f64	value;

	value = 1;
	if (pow < 0)
	{
		while (pow)
		{
			value /= 10;
			pow++;
		}
	}
	else
	{
		while (pow)
		{
			value *= 10;
			pow--;
		}
	}
	return (value);
}

t_f80	ft_f80_10pow(t_i16 pow)
{
	t_f80	value;

	value = 1;
	if (pow < 0)
	{
		while (pow)
		{
			value /= 10;
			pow++;
		}
	}
	else
	{
		while (pow)
		{
			value *= 10;
			pow--;
		}
	}
	return (value);
}

t_f128	ft_f128_10pow(t_i16 pow)
{
	t_f128	value;

	value = 1;
	if (pow < 0)
	{
		while (pow)
		{
			value /= 10;
			pow++;
		}
	}
	else
	{
		while (pow)
		{
			value *= 10;
			pow--;
		}
	}
	return (value);
}
