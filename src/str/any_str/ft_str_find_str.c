/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:19:16 by velimir           #+#    #+#             */
/*   Updated: 2023/02/19 03:08:33 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/mem/mem.h"
#include <stdbool.h>

bool	ft_str_find_str(
	t_any_str *haystack, t_any_str *needle,
	size_t *index
) {
	size_t	i;

	i = 0;
	while (i < haystack->len - needle->len)
	{
		if (ft_mem_equal(haystack->c_str + i, needle->c_str, needle->len))
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_str_find_str_rev(
	t_any_str *haystack, t_any_str *needle,
	size_t *index
) {
	size_t	i;

	i = haystack->len - needle->len;
	while (i > 0)
	{
		if (ft_mem_equal(haystack->c_str + i - 1, needle->c_str, needle->len))
		{
			*index = i - 1;
			return (true);
		}
		i--;
	}
	return (false);
}
