/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstrip.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:35:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 05:55:54 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/string.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/mem.h"

bool	ft_string_rstrip(t_string *string, char *stripped)
{
	t_str	stripped_str;
	t_u32	end;

	stripped_str = ft_str_from_c_str(stripped);
	end = 0;
	while (end < string->len)
	{
		if (!ft_str_contains_char(stripped_str,
				string->c_str[string->len - 1 - end]))
			break ;
		end++;
	}
	string->len -= end;
	return (true);
}
