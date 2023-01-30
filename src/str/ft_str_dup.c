/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 07:46:33 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_mem.h"
#include "libft_math.h"
#include "libft_c_str.h"

bool	ft_str_dup(t_str *dest, const t_str src)
{
	dest->len = src.len;
	dest->capacity = ft_alloc_capacity(dest->len + 1);
	if (!ft_mem_malloc(&dest->c_str, dest->capacity))
		return (false);
	ft_c_str_ncopy(dest->c_str, src.c_str, dest->len);
	return (true);
}
