/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:21:06 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 11:18:29 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/array/array_internals.h"
#include <libft/data/mem/mem.h>

bool	_ft_array_compare_elems(
	t_any_array *array, t_comparison_func func, t_u32 i, t_u32 j
) {
	void	*first;
	void	*second;

	first = ft_array_at(array, i);
	second = ft_array_at(array, j);
	if (!func)
		return (ft_mem_compare(first, second, array->elem_size) > 0);
	return (func(first, second));
}