/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:53:33 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 16:23:00 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internals.h"
#include "libft/fixed_types.h"
#include "libft/mem/mem.h"
#include <stdbool.h>

bool	ft_str_rfind_char(t_any_str *haystack, char c, t_u32 *index)
{
	t_u32	i;

	i = 0;
	while (i < haystack->len)
	{
		if (haystack->c_str[haystack->len - 1 - i] == c)
		{
			*index = haystack->len - 1 - i;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_str_rfind_str(t_any_str *haystack, t_any_str *needle, t_u32 *index)
{
	t_u32	i;

	i = 0;
	while (i + needle->len < haystack->len + 1)
	{
		if (ft_mem_equal(
				haystack->c_str + haystack->len - i - needle->len,
				needle->c_str,
				needle->len
			))
		{
			*index = haystack->len - i - needle->len;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_str_rfind_c_str(t_any_str *haystack, char *needle, t_u32 *index)
{
	t_u32	needle_len;
	t_u32	i;

	needle_len = ft_c_str_len(needle);
	i = 0;
	while (i + needle_len < haystack->len + 1)
	{
		if (ft_mem_equal(
				haystack->c_str + haystack->len - i - needle_len,
				needle,
				needle_len
			))
		{
			*index = haystack->len - i - needle_len;
			return (true);
		}
		i++;
	}
	return (false);
}
