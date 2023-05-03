/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:41:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 23:12:26 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internals.h"

void	ft_mem_copy(t_mem *dest, const t_mem *src, t_u32 size)
{
	t_u32	i;

	if (src == dest)
		return ;
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}
