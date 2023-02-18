/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:40:36 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/18 20:59:47 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internal_types.h"
#include <stddef.h>

void	ft_mem_zero(t_mem *ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
}
