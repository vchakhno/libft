/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:55:42 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 21:08:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include "libft/arithmetic/fixed_types.h"
# include "libft/io/ostream.h"

typedef struct s_vector
{
	void		*elems;
	t_u32		size;
	t_u32		elem_size;
	t_u32		capacity;
}	t_vector;

/******************************************************************************/
/* ALLOCATION																  */
/******************************************************************************/

void	ft_vector_alloc_empty(t_vector *vec, t_u32 elem_size);
void	ft_vector_free(t_vector *vec);

/******************************************************************************/
/* CAPACITY																	  */
/******************************************************************************/

bool	ft_vector_reserve(t_vector *vec, t_u32 additionnal);
bool	ft_vector_compact(t_vector *vec);

/******************************************************************************/
/* INSERTION																  */
/******************************************************************************/

bool	ft_vector_push(t_vector *vec, void *value);
bool	ft_vector_push_multiple(t_vector *vec, void *values, t_u32 count);
bool	ft_vector_insert(t_vector *vec, t_u32 i, void *value);
bool	ft_vector_insert_multiple(t_vector *vec,
			t_u32 i, void *values, t_u32 count);

/******************************************************************************/
/* REMOVAL																	  */
/******************************************************************************/

bool	ft_vector_pop(t_vector *vec, void *dest);
t_u32	ft_vector_pop_multiple(t_vector *vec, void *dest, t_u32 count);
bool	ft_vector_remove(t_vector *vec, t_u32 i, void *dest);
t_u32	ft_vector_remove_multiple(t_vector *vec,
			t_u32 i, void *dest, t_u32 count);
bool	ft_vector_swap_remove(t_vector *vec, t_u32 i, void *dest);
t_u32	ft_vector_swap_remove_multiple(t_vector *vec,
			t_u32 i, void *dest, t_u32 count);

#endif