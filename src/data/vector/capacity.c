/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:10:29 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 12:23:30 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/vector.h"
#include <stdlib.h>
#include <libft/data/mem/mem.h>

bool	ft_vector_reserve(t_vector *vec, t_u32 additionnal)
{
	void	*new_elems;

	if (vec->size + additionnal <= vec->capacity)
		return (true);
	if (!ft_mem_malloc(&new_elems,
			(vec->size + additionnal) * vec->elem_size))
		return (false);
	vec->capacity = vec->size + additionnal;
	ft_mem_copy(new_elems, vec->elems, vec->size * vec->elem_size);
	free(vec->elems);
	vec->elems = new_elems;
	return (true);
}

bool	ft_vector_compact(t_vector *vec)
{
	void	*new_elems;

	if (vec->capacity == vec->size)
		return (true);
	if (!ft_mem_malloc(&new_elems, vec->size * vec->elem_size))
		return (false);
	vec->capacity = vec->size;
	ft_mem_copy(new_elems, vec->elems, vec->size * vec->elem_size);
	free(vec->elems);
	vec->elems = new_elems;
	return (true);
}
