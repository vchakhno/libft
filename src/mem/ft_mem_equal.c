/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:41:10 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/18 20:57:40 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internal_types.h"
#include <stddef.h>
#include <stdbool.h>

bool	ft_mem_equal(const t_mem *ptr1, const t_mem *ptr2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (false);
		i++;
	}
	return (true);
}
