/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2022/10/17 17:50:02 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	joined = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		joined[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		joined[i + j] = str2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}
