/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:40:36 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 19:43:15 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/mem/mem.h"

void	ft_mem_zero(t_mem *mem, t_u32 size)
{
	t_byte *const	bytes = mem;
	t_u32			i;

	i = 0;
	while (i < size)
	{
		bytes[i] = 0;
		i++;
	}
}
