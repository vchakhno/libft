/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rstrip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:35:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 16:36:05 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str.h"
#include "libft/fixed_types.h"
#include "libft/mem/mem.h"

bool	ft_str_rstrip(t_allocated_str *str, char *stripped)
{
	t_borrowed_str	stripped_str;
	t_u32			end;

	stripped_str = ft_c_str_borrow(stripped);
	end = 0;
	while (end < str->len)
	{
		if (!ft_str_contains_char(&stripped_str,
				str->c_str[str->len - 1 - end]))
			break ;
		end++;
	}
	str->len -= end;
	return (true);
}
