/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reserve_pow2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 02:00:19 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:26:13 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/str.h"
#include "libft/math.h"

bool	ft_str_reserve_pow2(t_str *str, size_t capacity)
{
	return (ft_str_reserve_exact(str, ft_math_ceil_pow2(capacity)));
}
