/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ljust.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 04:47:55 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:47:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str.h"
#include "libft/data/mem.h"

bool	ft_str_ljust(t_allocated_str *str, t_u32 size, char filler)
{
	if (str->len >= size)
		return (true);
	if (!ft_str_reserve(str, str->len - size))
		return (false);
	ft_mem_set(str->c_str + str->len, size - str->len, filler);
	str->len = size;
	return (true);
}
