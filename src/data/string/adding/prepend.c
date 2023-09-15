/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:59:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/09/16 00:48:17 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/string.h"
#include "libft/data/mem.h"
#include <stdlib.h>
#include <stdbool.h>

// Adjusts to upper power of two, with minimum 2^1 (=2)
static	t_u32	ft_pow2_capacity(t_u32 capacity)
{
	t_u32	i;

	i = 1;
	while (capacity >> i)
		i++;
	return (1 << i);
}

bool	ft_string_prepend_str(t_string *string, t_str prefix)
{
	t_u32	new_capacity;
	char	*new_c_str;

	if (string->len + prefix.len <= string->capacity)
		ft_mem_move(string->c_str + prefix.len, string->c_str, string->len);
	else
	{
		new_capacity = ft_pow2_capacity(string->len + prefix.len);
		if (!ft_mem_malloc(&new_c_str, new_capacity))
			return (false);
		ft_mem_copy(new_c_str + prefix.len, string->c_str, string->len);
		free(string->c_str);
		string->c_str = new_c_str;
		string->capacity = new_capacity;
	}
	ft_mem_copy(string->c_str, prefix.c_str, prefix.len);
	string->len += prefix.len;
	return (true);
}

bool	ft_string_prepend_c_str(t_string *string, char *prefix)
{
	return (ft_string_prepend_str(string, ft_str_from_c_str(prefix)));
}
