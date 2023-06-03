/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:26:01 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 18:58:24 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/array/array_internals.h"
#include "libft/data/mem/mem.h"

bool	_ft_array_elem_equal(t_any_array *array,
			t_u32 i, void *data, t_equality_func func);

bool	ft_array_contains(t_any_array *array, void *data, t_equality_func func)
{
	t_u32	i;

	i = 0;
	while (i < array->size)
	{
		if (_ft_array_elem_equal(array, i, data, func))
			return (true);
		i++;
	}
	return (false);
}
