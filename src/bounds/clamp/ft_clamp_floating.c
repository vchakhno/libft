/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp_floating.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:20:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/04/30 10:48:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/bounds.h>

t_f32	ft_f32_clamp(t_f32 min, t_f32 value, t_f32 max)
{
	return (ft_f32_min(ft_f32_max(min, value), max));
}

t_f64	ft_f64_clamp(t_f64 min, t_f64 value, t_f64 max)
{
	return (ft_f64_min(ft_f64_max(min, value), max));
}

t_f128	ft_f128_clamp(t_f128 min, t_f128 value, t_f128 max)
{
	return (ft_f128_min(ft_f128_max(min, value), max));
}
