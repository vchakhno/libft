/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2023/01/19 08:17:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static bool	ft_startswith(const char *str, const char *prefix)
{
	size_t	i;

	i = 0;
	while (prefix[i])
	{
		if (str[i] != prefix[i])
			return (false);
		i++;
	}
	return (true);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	i = 0;
	while (i <= len - needle_len && haystack[i])
	{
		if (ft_startswith(haystack + i, needle))
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
