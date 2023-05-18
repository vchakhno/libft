/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstrip.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:35:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:29:58 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/mem/mem.h"

bool	ft_str_lstrip(t_allocated_str *str, char *set)
{
	t_borrowed_str	borrowed_set;
	t_u32			start;

	borrowed_set = ft_c_str_borrow(set);
	start = 0;
	while (start < str->len)
	{
		if (!ft_str_contains_char(&borrowed_set, str->c_str[start]))
			break ;
		start++;
	}
	str->len -= start;
	ft_mem_copy(str->c_str, str->c_str + start, str->len);
	return (true);
}
