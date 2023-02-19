/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:19:16 by velimir           #+#    #+#             */
/*   Updated: 2023/02/19 03:02:34 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include <stdbool.h>

bool	ft_str_find_char(t_any_str *haystack, char c, size_t *index)
{
	size_t	i;

	i = 0;
	while (i < haystack->len)
	{
		if (haystack->c_str[i] == c)
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_str_find_char_rev(t_any_str *haystack, char c, size_t *index)
{
	size_t	i;

	i = haystack->len;
	while (i > 0)
	{
		if (haystack->c_str[i - 1] == c)
		{
			*index = i - 1;
			return (true);
		}
		i--;
	}
	return (false);
}
