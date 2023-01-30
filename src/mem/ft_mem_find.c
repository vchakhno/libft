/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:38:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:27:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

void	*ft_mem_find(const void *ptr, size_t size, t_byte b)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((t_byte *) ptr)[i] == b)
			return ((void *) ptr + i);
		i++;
	}
	return (NULL);
}
