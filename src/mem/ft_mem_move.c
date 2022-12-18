/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:38:38 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/08 05:39:29 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

void	ft_mem_move(void *dest, const void *src, size_t size)
{
	size_t	i;

	if (src == dest)
		return ;
	i = 0;
	if (src < dest)
	{
		while (i < size)
		{
			((t_byte *) dest)[size - i - 1] = ((t_byte *) src)[size - i - 1];
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			((t_byte *) dest)[i] = ((t_byte *) src)[i];
			i++;
		}
	}
}
