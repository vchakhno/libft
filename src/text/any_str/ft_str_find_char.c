/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:19:16 by velimir           #+#    #+#             */
/*   Updated: 2023/02/18 23:11:50 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/any_str_internal.h"

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
