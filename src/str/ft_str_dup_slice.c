/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dup_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/17 01:00:23 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_math.h"

bool	ft_str_dup_slice(
	const t_str str,
	t_str *dupped,
	size_t start, size_t len
) {
	start = ft_math_min_size_t(start, str.len);
	len = ft_math_min_size_t(len, str.len - start);
	return (ft_str_alloc(dupped, str.c_str + start, len));
}
