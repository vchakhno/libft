/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_internal_types.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:34:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/18 19:46:32 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_INTERNAL_TYPES_H
# define MEM_INTERNAL_TYPES_H

# include <stddef.h>
# include <stdbool.h>

typedef char	t_byte;
typedef t_byte	t_mem;
typedef void*	t_ptr;

typedef struct s_maybe_byte_pos
{
	bool	exists;
	size_t	index;
	t_mem	*ptr;
}	t_maybe_byte_pos;

typedef struct s_find_byte_options
{
	size_t	*out_index;
	t_ptr	*out_ptr;
}	t_find_byte_options;

#endif