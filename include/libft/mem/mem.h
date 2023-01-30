/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 11:21:38 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include "mem_def.h"
# include <stddef.h>
# include <stdbool.h>

/******************************************************************************/
/* ALLOCATION																  */
/******************************************************************************/

bool				ft_mem_malloc(void *dest, size_t size)
					__attribute__((warn_unused_result));
void				*ft_mem_calloc(size_t count, size_t size)
					__attribute__((warn_unused_result));

/******************************************************************************/
/* COMPARISON																  */
/******************************************************************************/

bool				ft_mem_equal(const t_mem *ptr1, const t_mem *ptr2,
						size_t n);
int					ft_mem_compare(const t_mem *ptr1, const t_mem *ptr2,
						size_t n);

/******************************************************************************/
/* SEARCH																	  */
/******************************************************************************/

typedef struct s_maybe_byte_pos
{
	bool	exists;
	size_t	index;
	t_byte	*ptr;
}	t_maybe_byte_pos;

typedef struct s_find_byte_options
{
	size_t	*out_index;
	t_byte	**out_ptr;
}	t_find_byte_options;

t_maybe_byte_pos	*ft_mem_find_byte(const t_mem *ptr, size_t size, t_byte b,
						t_find_byte_options *options);

/******************************************************************************/
/* ASSIGNEMENT																  */
/******************************************************************************/

void				ft_mem_copy(t_mem *dest, const t_mem *src, size_t size);
void				ft_mem_move(t_mem *dest, const t_mem *src, size_t size);
void				ft_mem_swap(t_mem *ptr1, t_mem *ptr2, size_t size);
void				ft_mem_set(t_mem *ptr, size_t size, t_byte b);
void				ft_mem_zero(t_mem *ptr, size_t size);

#endif