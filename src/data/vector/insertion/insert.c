/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:01:53 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:48:14 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/vector.h"
#include "libft/data/array.h"
#include <stdlib.h>
#include "libft/data/mem.h"

bool	ft_vector_insert(t_vector *vec, t_u32 index, void *value)
{
	return (ft_vector_insert_multiple(vec, index, value, 1));
}

bool	ft_vector_insert_multiple(
	t_vector *vec, t_u32 i, void *values, t_u32 count
) {
	void	*old_elems;

	old_elems = vec->elems;
	if (vec->size + count > vec->capacity)
	{
		if (!ft_mem_malloc(&vec->elems, (vec->size + count) * vec->elem_size))
		{
			vec->elems = old_elems;
			return (false);
		}
		vec->capacity = vec->size + count;
		ft_mem_copy(vec->elems, old_elems, i * vec->elem_size);
	}
	ft_mem_move(
		ft_array_at(vec, i + count),
		old_elems + i * vec->elem_size,
		(vec->size - i) * vec->elem_size);
	if (old_elems != vec->elems)
		free(old_elems);
	ft_mem_copy(ft_array_at(vec, i), values, count * vec->elem_size);
	vec->size += count;
	return (true);
}
