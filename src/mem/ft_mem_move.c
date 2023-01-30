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

#include "libft/mem/mem_internal.h"

void	ft_mem_move(t_mem *dest, const t_mem *src, size_t size)
{
	size_t	i;

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
