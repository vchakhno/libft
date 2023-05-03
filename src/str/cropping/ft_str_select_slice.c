/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_select_slice.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:02:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 15:33:05 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str.h"
#include "libft/mem/mem.h"

void	ft_str_select_slice(t_allocated_str *str, t_u32 start, t_u32 len)
{
	ft_mem_copy(str->c_str, str->c_str + start, len);
	str->len = len;
}
