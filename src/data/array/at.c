/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:11:49 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 19:04:26 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/array/array.h"

void	*ft_array_at(t_any_array *any_array, t_u32 i)
{
	t_borrowed_array *const	array = any_array;

	return (array->elems + i * array->elem_size);
}
