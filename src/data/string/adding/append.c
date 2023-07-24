/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:59:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 05:50:51 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/string.h"
#include "libft/data/mem.h"

bool	ft_string_append_str(t_string *string, t_str suffix)
{
	if (!ft_string_reserve(string, suffix.len))
		return (false);
	ft_mem_copy(string->c_str + string->len, suffix.c_str, suffix.len);
	string->len += suffix.len;
	return (true);
}

bool	ft_string_append_c_str(t_string *string, char *suffix)
{
	return (ft_string_append_str(string, ft_str_from_c_str(suffix)));
}
