/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dup_c_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 07:45:28 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_mem.h"
#include "libft_math.h"
#include "libft_c_str.h"

bool	ft_str_dup_c_str(t_str *str, const char *c_str)
{
	str->len = ft_c_str_len(c_str);
	str->capacity = ft_alloc_capacity(str->len + 1);
	if (!ft_mem_malloc(&str->c_str, str->capacity))
		return (false);
	ft_c_str_ncopy(str->c_str, c_str, str->len);
	return (true);
}
