/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:19:18 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/19 01:21:56 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_TYPES_H
# define STR_TYPES_H

# include <stddef.h>

typedef struct s_borrowed_str
{
	char	*c_str;
	size_t	len;
}	t_borrowed_str;

typedef struct s_allocated_str
{
	char	*c_str;
	size_t	len;
	size_t	capacity;
}	t_allocated_str;

typedef t_allocated_str		t_str;
typedef t_borrowed_str		t_str_slice;
typedef void				t_any_str;

#endif