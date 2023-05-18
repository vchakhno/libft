/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:56:30 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 12:23:30 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/vector.h"
#include <stdlib.h>

void	ft_vector_alloc_empty(t_vector *vec, t_u32 elem_size)
{
	vec->elem_size = elem_size;
	vec->size = 0;
	vec->capacity = 0;
	vec->elems = NULL;
}

void	ft_vector_free(t_vector *vec)
{
	free(vec->elems);
}
