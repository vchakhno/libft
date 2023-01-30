/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:02:39 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 11:16:46 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internal.h"

void	ft_mem_swap(t_mem *ptr1, t_mem *ptr2, size_t n)
{
	size_t	i;
	t_byte	t;

	i = 0;
	while (i < n)
	{
		t = ptr1[i];
		ptr1[i] = ptr2[i];
		ptr2[i] = t;
		i++;
	}
}
