/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borrowing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:58:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 11:18:06 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/array/array_internals.h"
#include <libft/arithmetic/bounds.h>

t_borrowed_array	ft_borrowed_array_from_parts(
	void *elems, t_u32 elem_size, t_u32 size
) {
	t_borrowed_array	array;

	array.elems = elems;
	array.size = size;
	array.elem_size = elem_size;
	return (array);
}

t_borrowed_array	array_borrow(t_any_array *array)
{
	return (*array);
}

t_borrowed_array	array_borrow_slice__unchecked(
	t_any_array *array, t_u32 start, t_u32 len
) {
	t_borrowed_array	borrowed;

	borrowed.elems = ft_array_at(array, start);
	borrowed.size = len;
	borrowed.elem_size = array->elem_size;
	return (borrowed);
}

t_borrowed_array	array_borrow_slice(
	t_any_array *array, t_u32 start, t_u32 len
) {
	t_borrowed_array	borrowed;

	start = ft_u32_min(start, array->size);
	borrowed.elems = ft_array_at(array, start);
	borrowed.size = ft_u32_min(len, array->size - start);
	borrowed.elem_size = array->elem_size;
	return (borrowed);
}
