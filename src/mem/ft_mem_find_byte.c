/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_find_byte.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:38:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/19 03:08:16 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internal_types.h"
#include <stddef.h>
#include <stdbool.h>

bool	ft_mem_find_byte(
	const t_mem *ptr, size_t size, t_byte b,
	size_t *index
) {
	size_t	i;

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
