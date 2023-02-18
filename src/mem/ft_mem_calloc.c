/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_calloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:38:11 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/18 20:57:03 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internal_types.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool	ft_mem_malloc(t_ptr *ptr, size_t size);
void	ft_mem_zero(t_mem *ptr, size_t size);

bool	ft_mem_calloc(t_ptr *ptr, size_t count, size_t size)
{
	if (size != 0 && count > SIZE_MAX / size)
		return (false);
	if (ft_mem_malloc(ptr, count * size))
		ft_mem_zero(*ptr, count * size);
	return (*ptr);
}
