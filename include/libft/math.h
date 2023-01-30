/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 01:50:01 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 08:23:25 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

#include <stddef.h>

size_t	ft_math_ceil_pow2(size_t n);
size_t	ft_math_min_size_t(size_t a, size_t b);
size_t	ft_math_max_size_t(size_t a, size_t b);
size_t	ft_alloc_capacity(size_t capacity);

#endif