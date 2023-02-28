/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_lstrip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:35:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/28 07:30:56 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/mem/mem.h"

bool	ft_str_lstrip(t_allocated_str *str, char *stripped)
{
	t_borrowed_str	stripped_str;
	size_t			start;

	stripped_str = ft_c_str_borrow(stripped);
	start = 0;
	while (start < str->len)
	{
		if (!ft_str_contains_char(&stripped_str, str->c_str[start]))
			break ;
		start++;
	}
	str->len -= start;
	ft_mem_copy(str->c_str, str->c_str + start, str->len);
	return (true);
}
