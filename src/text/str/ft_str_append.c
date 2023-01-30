/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 08:28:18 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/str.h"
#include "libft_c_str.h"
#include <stdio.h>

bool	ft_str_append(t_str *str, const void *suffix_str)
{
	t_str_slice	*suffix;

	suffix = (t_str_slice *) suffix_str;
	if (str->len + suffix->len >= str->capacity)
	{
		if (!ft_str_reserve_pow2(str, str->len + suffix->len + 1))
			return (false);
	}
	ft_c_str_ncopy(str->c_str + str->len, suffix->c_str, suffix->len);
	str->len += suffix->len;
	return (true);
}
