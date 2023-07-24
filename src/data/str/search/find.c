/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:53:33 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 05:21:11 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/mem.h"

bool	ft_str_find_char(t_str haystack, char c, t_u32 *index)
{
	t_u32	i;

	i = 0;
	while (i < haystack.len)
	{
		if (haystack.c_str[i] == c)
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_str_find_str(t_str haystack, t_str needle, t_u32 *index)
{
	t_u32	i;

	i = 0;
	while (i + needle.len < haystack.len + 1)
	{
		if (ft_mem_equal(haystack.c_str + i, needle.c_str, needle.len))
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_str_find_c_str(t_str haystack, char *needle, t_u32 *index)
{
	t_u32	needle_len;
	t_u32	i;

	needle_len = ft_c_str_len(needle);
	i = 0;
	while (i + needle_len < haystack.len + 1)
	{
		if (ft_mem_equal(haystack.c_str + i, needle, needle_len))
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}
