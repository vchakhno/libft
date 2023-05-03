/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rjust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 04:47:55 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 16:39:57 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str.h"
#include "libft/mem/mem.h"
#include <stdlib.h>

bool	ft_str_rjust(t_allocated_str *str, t_u32 size, char filler)
{
	char	*new_c_str;

	if (str->len >= size)
		return (true);
	if (size > str->capacity)
	{
		if (!ft_mem_malloc(&new_c_str, size))
			return (false);
		str->capacity = size;
		ft_mem_copy(new_c_str + size - str->len, str->c_str, str->len);
		free(str->c_str);
		str->c_str = new_c_str;
	}
	else
	{
		ft_mem_move(str->c_str + size - str->len, str->c_str, str->len);
	}
	ft_mem_set(str->c_str, size - str->len, filler);
	str->len = size;
	return (true);
}
