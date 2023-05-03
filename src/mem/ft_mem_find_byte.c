/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_find_byte.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:38:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 23:12:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internals.h"

bool	ft_mem_find_byte(
	const t_mem *ptr, t_u32 size, t_byte b, t_u32 *index
) {
	t_u32	i;

	i = 0;
	while (i < size)
	{
		if (ptr[i] == b)
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}
