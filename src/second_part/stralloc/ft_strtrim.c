/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2022/10/17 17:49:38 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

static bool	ft_str_contains(char const *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

static char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && str[start + i])
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	start;
	size_t	len;
	size_t	i;

	i = 0;
	while (ft_str_contains(set, str[i]))
		i++;
	start = i;
	while (str[i])
	{
		if (!ft_str_contains(set, str[i]))
			len = i - start + 1;
		i++;
	}
	return (ft_substr(str, start, len));
}
