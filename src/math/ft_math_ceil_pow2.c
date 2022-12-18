/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_ceil_pow2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 01:52:04 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/16 10:26:52 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

size_t	ft_math_ceil_pow2(size_t n)
{
	size_t	pow;

	pow = 0;
	while (pow < sizeof(size_t) * 8 && 1lu << pow < n)
		pow++;
	return (1 << pow);
}
