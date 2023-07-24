/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:59:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 05:49:46 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/string.h"
#include "libft/data/mem.h"
#include <stdlib.h>

bool	ft_string_reserve(t_string *string, t_u32 additionnal)
{
	char	*new_c_str;

	if (string->len + additionnal <= string->capacity)
		return (true);
	if (!ft_mem_malloc(&new_c_str, string->len + additionnal))
		return (false);
	string->capacity = string->len + additionnal;
	ft_mem_copy(new_c_str, string->c_str, string->len);
	free(string->c_str);
	string->c_str = new_c_str;
	return (true);
}

bool	ft_string_compact(t_string *string)
{
	char	*new_c_str;

	if (string->capacity == string->len)
		return (true);
	if (!ft_mem_malloc(&new_c_str, string->len))
		return (false);
	string->capacity = string->len;
	ft_mem_copy(new_c_str, string->c_str, string->len);
	free(string->c_str);
	string->c_str = new_c_str;
	return (true);
}
