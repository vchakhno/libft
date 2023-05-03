/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:38:38 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 23:13:51 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internals.h"

void	ft_mem_move(t_mem *dest, const t_mem *src, t_u32 size)
{
	t_u32	i;

	if (src == dest)
		return ;
	i = 0;
	if (src < dest)
	{
		while (i < size)
		{
			dest[size - i - 1] = src[size - i - 1];
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			dest[i] = src[i];
			i++;
		}
	}
}
