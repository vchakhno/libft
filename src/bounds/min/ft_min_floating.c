/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_floating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:20:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/02 09:47:43 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/bounds.h"

t_f32	ft_f32_min(t_f32 a, t_f32 b)
{
	if (a < b)
		return (a);
	return (b);
}

t_f64	ft_f64_min(t_f64 a, t_f64 b)
{
	if (a < b)
		return (a);
	return (b);
}

t_f128	ft_f128_min(t_f128 a, t_f128 b)
{
	if (a < b)
		return (a);
	return (b);
}
