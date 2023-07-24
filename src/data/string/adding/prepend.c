/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:59:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 05:52:20 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/string.h"
#include "libft/data/mem.h"
#include <stdlib.h>
#include <stdbool.h>

bool	ft_string_prepend_str(t_string *string, t_str prefix)
{
	char	*new_c_str;

	if (string->len + prefix.len > string->capacity)
	{
		if (!ft_mem_malloc(&new_c_str, string->len + prefix.len))
			return (false);
		ft_mem_copy(new_c_str + prefix.len, string->c_str, string->len);
		free(string->c_str);
		string->c_str = new_c_str;
	}
	else
	{
		ft_mem_move(string->c_str + prefix.len, string->c_str, string->len);
	}
	ft_mem_copy(string->c_str, prefix.c_str, prefix.len);
	string->len += prefix.len;
	return (true);
}

bool	ft_string_prepend_c_str(t_string *string, char *prefix)
{
	return (ft_string_prepend_str(string, ft_str_from_c_str(prefix)));
}
