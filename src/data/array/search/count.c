/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:30:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:48:14 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/array.h"
#include "libft/data/mem.h"

bool	_ft_array_elem_equal(t_borrowed_array *array,
			t_u32 i, void *data, t_equality_func func);

t_u32	ft_array_count(t_any_array *any_array, void *data, t_equality_func func)
{
	t_borrowed_array *const	array = any_array;
	t_u32					i;
	t_u32					count;

	count = 0;
	i = 0;
	while (i < array->size)
	{
		if (_ft_array_elem_equal(array, i, data, func))
			count++;
		i++;
	}
	return (count);
}
