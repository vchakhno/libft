/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_substr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:41:08 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:26:15 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/str.h"
#include "libft/math.h"

bool	ft_str_substr(t_str *sub, const t_str str, size_t from, size_t len)
{
	return (ft_str_alloc(
			sub,
			str.c_str + ft_math_min_size_t(from, str.len),
			ft_math_min_size_t(len, str.len - from)
		));
}
