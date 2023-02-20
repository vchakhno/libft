/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:53:33 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/20 12:13:13 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/mem/mem.h"
#include <stdbool.h>

bool	ft_str_rfind_char(t_any_str *haystack, char c, size_t *index)
{
	size_t	i;

	i = haystack->len;
	while (i > 0)
	{
		i--;
		if (haystack->c_str[i] == c)
		{
			*index = i;
			return (true);
		}
	}
	return (false);
}

bool	ft_str_rfind_str(t_any_str *haystack, t_any_str *needle, size_t *index)
{
	size_t	i;

	i = haystack->len - needle->len + 1;
	while (i > 0)
	{
		i--;
		if (ft_mem_equal(haystack->c_str + i, needle->c_str, needle->len))
		{
			*index = i;
			return (true);
		}
	}
	return (false);
}

bool	ft_str_rfind_c_str(t_any_str *haystack, char *needle, size_t *index)
{
	size_t	needle_len;
	size_t	i;

	needle_len = ft_c_str_len(needle);
	i = haystack->len - needle_len + 1;
	while (i > 0)
	{
		i--;
		if (ft_mem_equal(haystack->c_str + i, needle, needle_len))
		{
			*index = i;
			return (true);
		}
	}
	return (false);
}

