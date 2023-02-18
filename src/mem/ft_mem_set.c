/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:41:32 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/18 20:59:34 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internal_types.h"
#include <stddef.h>

void	ft_mem_set(t_mem *ptr, size_t size, t_byte b)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ptr[i] = b;
		i++;
	}
}
