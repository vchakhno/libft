/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/18 21:00:31 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <stddef.h>
# include <stdbool.h>
# ifndef MEM_INTERNAL_TYPES_H
#  include "mem_types.h"
# endif

/******************************************************************************/
/* ALLOCATION																  */
/******************************************************************************/

/*
	WARNING:

	In mem_malloc and mem_calloc, the destination should be **the address**
	of the pointer.
	Example:
	
	int	*array;

	if (!ft_mem_calloc(&array, 5, sizeof(int)))
		return (false);
*/

bool				ft_mem_malloc(t_ptr *ptr, size_t size)
					__attribute__((warn_unused_result));
bool				ft_mem_calloc(t_ptr *ptr, size_t count, size_t size)
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