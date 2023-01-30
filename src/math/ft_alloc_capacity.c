/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_capacity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 01:53:59 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:26:04 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

size_t	ft_alloc_capacity(size_t capacity)
{
	return (ft_math_max_size_t(ft_math_ceil_pow2(capacity), 8));
}
