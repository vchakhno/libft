/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:19:16 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 03:13:02 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *) str + i);
		i++;
	}
	if (str[i] == c)
		return ((char *) str + i);
	return (NULL);
}

char	*ft_strrchr(const char *str, int c)
{
	char	*found;
	size_t	i;

	found = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			found = ((char *) str + i);
		i++;
	}
	if (str[i] == c)
		return ((char *) str + i);
	return (found);
}
