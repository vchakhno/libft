/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:23:44 by velimir           #+#    #+#             */
/*   Updated: 2022/10/16 02:55:15 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (dest > src)
			((char *)dest)[size - 1 - i] = ((char *)src)[size - 1 - i];
		else
			((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
