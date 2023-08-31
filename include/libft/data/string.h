/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 05:56:36 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# include "libft/data/string.h"
# undef STRING_H
#else
# ifndef LIBFT_STRING_H
#  define LIBFT_STRING_H

#  include <stdbool.h>
#  include "libft/arithmetic/fixed_types.h"
#  include "libft/data/iterator.h"
#  include "libft/io/output.h"
#  include "libft/data/str.h"

typedef struct s_string
{
	union {
		t_str			str;
		struct {
			char		*c_str;
			t_u32		len;
		};
	};
	t_u32				capacity;
}	t_string;

/******************************************************************************/
/* ALLOCATION																  */
/******************************************************************************/

void	ft_string_alloc_empty(t_string *string);
bool	ft_string_from_c_str(t_string *string, char *c_str)
		__attribute__((warn_unused_result));
bool	ft_string_from_str(t_string *dest, t_str src)
		__attribute__((warn_unused_result));
void	ft_string_free(t_string *string);

/******************************************************************************/
/* CAPACITY																	  */
/******************************************************************************/

bool	ft_string_reserve(t_string *string, t_u32 additionnal)
		__attribute__((warn_unused_result));
bool	ft_string_compact(t_string *string)
		__attribute__((warn_unused_result));

/******************************************************************************/
/* ADDING																	  */
/******************************************************************************/

bool	ft_string_append_c_str(t_string *string, char *suffix);
bool	ft_string_prepend_c_str(t_string *string, char *prefix);
bool	ft_string_insert_c_str(t_string *string, t_u32 index, char *inserted);

bool	ft_string_append_str(t_string *string, t_str suffix);
bool	ft_string_prepend_str(t_string *string, t_str prefix);
bool	ft_string_insert_str(t_string *string, t_u32 index, t_str inserted);

/******************************************************************************/
/* CROPPING																	  */
/******************************************************************************/

void	ft_string_remove_slice(t_string *string, t_u32 start, t_u32 len);
void	ft_string_select_slice(t_string *string, t_u32 start, t_u32 len);

/******************************************************************************/
/* POSITIONNING																  */
/******************************************************************************/

bool	ft_string_center(t_string *string, t_u32 size, char filler);
bool	ft_string_ljust(t_string *string, t_u32 size, char filler);
bool	ft_string_rjust(t_string *string, t_u32 size, char filler);

/******************************************************************************/
/* STRIPPING																  */
/******************************************************************************/

bool	ft_string_lstrip(t_string *string, char *set);
bool	ft_string_rstrip(t_string *string, char *set);
bool	ft_string_strip(t_string *string, char *set);

bool	ft_string_remove_c_str_prefix(t_string *string, char *prefix);
bool	ft_string_remove_str_prefix(t_string *string, t_str prefix);
bool	ft_string_remove_c_str_suffix(t_string *string, char *suffix);
bool	ft_string_remove_str_suffix(t_string *string, t_str suffix);

/******************************************************************************/
/* FORMATTING																  */
/******************************************************************************/

/* Todo */
bool	ft_string_replace(t_string *string, t_str old, t_str new);
bool	ft_string_format(t_string *string, ...);
/* ---- */

/******************************************************************************/
/* JOINING																	  */
/******************************************************************************/

typedef t_any_iterator		t_str_iterator;

/* Todo */
bool	ft_string_join_with_str(t_string *dest,
			t_str_iterator *iterator, t_str sep);
bool	ft_string_join_with_c_str(t_string *dest,
			t_str_iterator *iterator, char *sep);
/* ---- */

# endif
#endif