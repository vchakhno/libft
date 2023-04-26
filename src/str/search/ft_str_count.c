/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:53:33 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/20 12:21:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/mem/mem.h"

size_t	ft_str_count_char(t_any_str *haystack, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < haystack->len)
	{
		if (haystack->c_str[i] == c)
			count++;
		i++;
	}
	return (count);
}

size_t	ft_str_count_str(t_any_str *haystack, t_any_str *needle)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < haystack->len - needle->len + 1)
	{
		if (ft_mem_equal(haystack->c_str + i, needle->c_str, needle->len))
			count++;
		i++;
	}
	return (count);
}

size_t	ft_str_count_c_str(t_any_str *haystack, char *needle)
{
	size_t	needle_len;
	size_t	count;
	size_t	i;

	needle_len = ft_c_str_len(needle);
	count = 0;
	i = 0;
	while (i < haystack->len - needle_len + 1)
	{
		if (ft_mem_equal(haystack->c_str + i, needle, needle_len))
			count++;
		i++;
	}
	return (count);
}
