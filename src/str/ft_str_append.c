/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/18 11:25:51 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

bool	ft_str_append(t_str *str, const t_str suffix)
{
	if (str->len + suffix.len >= str->capacity)
	{
		if (!ft_str_reserve_pow2(&str, str->len + suffix.len))
			return (false);
	}
	ft_c_str_ncopy(str->c_str + str->len, suffix.c_str, suffix.len);
	str->len += suffix.len;
	return (true);
}
