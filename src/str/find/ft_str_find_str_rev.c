/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_str_rev.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:19:16 by velimir           #+#    #+#             */
/*   Updated: 2022/12/09 09:29:15 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_str_find_str_rev(const t_str *haystack, const t_str *needle)
{
	size_t	i;

	if (needle.len > haystack.len)
		return (NULL);
	i = needle.len;
	while (i < haystack.len)
	{
		if (ft_mem_equals(
				haystack.c_str + haystack.len - 1 - i,
				needle.c_str, needle.len))
			return (haystack.c_str + i);
		i++;
	}
	return (NULL);
}
