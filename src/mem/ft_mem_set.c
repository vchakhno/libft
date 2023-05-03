/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:41:32 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 23:14:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internals.h"

void	ft_mem_set(t_mem *ptr, t_u32 size, t_byte b)
{
	t_u32	i;

	i = 0;
	while (i < size)
	{
		ptr[i] = b;
		i++;
	}
}
