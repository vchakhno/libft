/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:59:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:23:48 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include "libft/data/mem/mem.h"
#include <stdlib.h>

bool	ft_str_reserve(t_allocated_str *str, t_u32 additionnal)
{
	char	*new_c_str;

	if (str->len + additionnal <= str->capacity)
		return (true);
	if (!ft_mem_malloc(&new_c_str, str->len + additionnal))
		return (false);
	str->capacity = str->len + additionnal;
	ft_mem_copy(new_c_str, str->c_str, str->len);
	free(str->c_str);
	str->c_str = new_c_str;
	return (true);
}

bool	ft_str_compact(t_allocated_str *str)
{
	char	*new_c_str;

	if (str->capacity == str->len)
		return (true);
	if (!ft_mem_malloc(&new_c_str, str->len))
		return (false);
	str->capacity = str->len;
	ft_mem_copy(new_c_str, str->c_str, str->len);
	free(str->c_str);
	str->c_str = new_c_str;
	return (true);
}
