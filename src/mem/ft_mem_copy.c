/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:41:15 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/18 20:57:28 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internal_types.h"
#include <stddef.h>

void	ft_mem_copy(t_mem *dest, const t_mem *src, size_t size)
{
	size_t	i;

	if (src == dest)
		return ;
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}
