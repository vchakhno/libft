/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:41:10 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:22:51 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/mem/mem_internals.h"

bool	ft_mem_equal(const t_mem *ptr1, const t_mem *ptr2, t_u32 n)
{
	t_u32	i;

	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (false);
		i++;
	}
	return (true);
}
