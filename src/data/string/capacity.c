/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:59:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/09/16 00:40:00 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/string.h"
#include "libft/data/mem.h"
#include <stdlib.h>

// Adjusts to upper power of two, with minimum 2^1 (=2)
static	t_u32	ft_pow2_capacity(t_u32 capacity)
{
	t_u32	i;

	i = 1;
	while (capacity >> i)
		i++;
	return (1 << i);
}

bool	ft_string_reserve(t_string *string, t_u32 additionnal)
{
	t_u32	new_capacity;
	char	*new_c_str;

	if (string->len + additionnal <= string->capacity)
		return (true);
	new_capacity = ft_pow2_capacity(string->len + additionnal);
	if (!ft_mem_malloc(&new_c_str, new_capacity))
		return (false);
	ft_mem_copy(new_c_str, string->c_str, string->len);
	free(string->c_str);
	string->c_str = new_c_str;
	string->capacity = new_capacity;
	return (true);
}

bool	ft_string_reserve_exact(t_string *string, t_u32 additionnal)
{
	char	*new_c_str;

	if (string->len + additionnal <= string->capacity)
		return (true);
	if (!ft_mem_malloc(&new_c_str, string->len + additionnal))
		return (false);
	ft_mem_copy(new_c_str, string->c_str, string->len);
	free(string->c_str);
	string->c_str = new_c_str;
	string->capacity = string->len + additionnal;
	return (true);
}

bool	ft_string_compact(t_string *string)
{
	char	*new_c_str;

	if (string->capacity == string->len)
		return (true);
	if (!ft_mem_dup(&new_c_str, string->c_str, string->len))
		return (false);
	free(string->c_str);
	string->c_str = new_c_str;
	string->capacity = string->len;
	return (true);
}
