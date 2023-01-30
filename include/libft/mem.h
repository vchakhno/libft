/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:56:28 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <stddef.h>
# include <stdbool.h>

typedef unsigned char	t_byte;

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

int					ft_mem_compare(const void *ptr1, const void *ptr2,
						size_t n);
bool				ft_mem_equal(const void *ptr1, const void *ptr2, size_t n);
void				ft_mem_copy(void *dest, const void *src, size_t size);

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

t_maybe_byte_pos	*ft_mem_find_byte(const void *ptr, size_t size, t_byte b,
						t_find_byte_options *options);

/******************************************************************************/
/* ASSIGNEMENT																  */
/******************************************************************************/

void				ft_mem_move(void *dest, const void *src, size_t size);
void				ft_mem_set(void *ptr, size_t size, t_byte b);
void				ft_mem_zero(void *ptr, size_t size);

#endif