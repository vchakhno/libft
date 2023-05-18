/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_slice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:02:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:29:58 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include "libft/data/mem/mem.h"

void	ft_str_remove_slice(t_allocated_str *str, t_u32 start, t_u32 len)
{
	ft_mem_move(
		str->c_str + start,
		str->c_str + start + len,
		str->len - start - len);
	str->len -= len;
}
