/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rstrip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:35:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/28 07:39:49 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/mem/mem.h"

bool	ft_str_rstrip(t_allocated_str *str, char *stripped)
{
	t_borrowed_str	stripped_str;
	size_t			end;

	stripped_str = ft_c_str_borrow(stripped);
	end = str->len;
	while (end > 0)
	{
		if (!ft_str_contains_char(&stripped_str, str->c_str[end - 1]))
			break ;
		end--;
	}
	str->len = end;
	return (true);
}
