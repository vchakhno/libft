/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:59:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/14 08:27:30 by vchakhno         ###   ########.fr       */
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

bool	ft_string_insert_str(t_string *string, t_u32 index, t_str inserted)
{
	t_u32	new_capacity;
	char	*new_c_str;

	if (string->len + inserted.len <= string->capacity)
		ft_mem_move(
			string->c_str + index + inserted.len,
			string->c_str + index,
			string->len - index);
	else
	{
		new_capacity = ft_pow2_capacity(string->len + inserted.len);
		if (!ft_mem_malloc(&new_c_str, new_capacity))
			return (false);
		ft_mem_copy(new_c_str, string->c_str, index);
		ft_mem_copy(
			new_c_str + index + inserted.len,
			string->c_str + index,
			string->len - index);
		free(string->c_str);
		string->c_str = new_c_str;
		string->capacity = new_capacity;
	}
	ft_mem_copy(string->c_str + index, inserted.c_str, inserted.len);
	string->len += inserted.len;
	return (true);
}

bool	ft_string_insert_c_str(t_string *string, t_u32 index, char *inserted)
{
	return (ft_string_insert_str(string, index, ft_str(inserted)));
}
