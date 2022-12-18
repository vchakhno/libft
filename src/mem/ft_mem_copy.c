/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:41:15 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/18 11:32:34 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

void	ft_mem_copy(void *dest, const void *src, size_t size)
{
	size_t	i;

	if (src == dest)
		return ;
	i = 0;
	while (i < size)
	{
		((t_byte *) dest)[i] = ((t_byte *) src)[i];
		i++;
	}
}
