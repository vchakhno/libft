/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 04:42:56 by vchakhno         ###   ########.fr       */
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

typedef struct s_string
{
	char	*c_str;
	t_u32	len;
	t_u32	capacity;
}	t_string;

/******************************************************************************/
/* ALLOCATION																  */
/******************************************************************************/

void			ft_str_alloc_empty(t_allocated_str *str);
bool			ft_str_dup_c_str(t_allocated_str *str, char *c_str)
				__attribute__((warn_unused_result));
bool			ft_str_dup_str(t_allocated_str *dest, t_str *any_src)
				__attribute__((warn_unused_result));
void			ft_str_free(t_allocated_str *str);

/******************************************************************************/
/* CAPACITY																	  */
/******************************************************************************/

bool			ft_str_reserve(t_allocated_str *str, t_u32 additionnal)
				__attribute__((warn_unused_result));
bool			ft_str_compact(t_allocated_str *str)
				__attribute__((warn_unused_result));

/******************************************************************************/
/* ADDING																	  */
/******************************************************************************/

bool			ft_str_append_c_str(t_allocated_str *str, char *suffix);
bool			ft_str_prepend_c_str(t_allocated_str *str, char *prefix);
bool			ft_str_insert_c_str(t_allocated_str *str,
					t_u32 index, char *inserted);

bool			ft_str_append_str(t_allocated_str *str, t_str *any_suffix);
bool			ft_str_prepend_str(t_allocated_str *str, t_str *any_prefix);
bool			ft_str_insert_str(t_allocated_str *str,
					t_u32 index, t_str *any_inserted);

/******************************************************************************/
/* CROPPING																	  */
/******************************************************************************/

void			ft_str_remove_slice(t_allocated_str *str,
					t_u32 start, t_u32 len);
void			ft_str_select_slice(t_allocated_str *str,
					t_u32 start, t_u32 len);

/******************************************************************************/
/* POSITIONNING																  */
/******************************************************************************/

bool			ft_str_center(t_allocated_str *str, t_u32 size, char filler);
bool			ft_str_ljust(t_allocated_str *str, t_u32 size, char filler);
bool			ft_str_rjust(t_allocated_str *str, t_u32 size, char filler);

/******************************************************************************/
/* STRIPPING																  */
/******************************************************************************/

bool			ft_str_lstrip(t_allocated_str *str, char *set);
bool			ft_str_rstrip(t_allocated_str *str, char *set);
bool			ft_str_strip(t_allocated_str *str, char *set);

bool			ft_str_remove_c_str_prefix(t_allocated_str *str, char *prefix);
bool			ft_str_remove_str_prefix(t_allocated_str *str,
					t_str *any_prefix);
bool			ft_str_remove_c_str_suffix(t_allocated_str *str, char *suffix);
bool			ft_str_remove_str_suffix(t_allocated_str *str,
					t_str *any_suffix);

/******************************************************************************/
/* FORMATTING																  */
/******************************************************************************/

/* Todo */
bool			ft_str_replace(t_allocated_str *str,
					t_str *any_old, t_str *any_new);
bool			ft_str_format(t_allocated_str *str, ...);
/* ---- */

/*
	First variant:
		
		t_str_slice	suffix;

		suffix = ft_c_str_borrow("Velimir");
		if (!ft_str_append(str, &suffix))
		{
			// Error goes here
		}

	[-] Needs an extra variable, and an extra line
	[+] Can use existing strs
	
	Second variant:

		if (!ft_str_append(str, "Velimir"))
		{
			// Error goes here
		}
	
	[+] Very short
	[+] Easier to use
	[-] Cannot, at all, work with other strs.
		No conversion is possible.
	
	Third variant: (same proto as first)
	
		if (!ft_str_append(str, (t_str_slice []){ft_c_str_borrow("Velimir")}))
		{
			// Error goes here
		}
	
	[-] Uses harder concepts
	[+] Compatible with both strs and c_strs
	[+] Can be used inline

	Fourth variant: (same proto as first, different borrowing)

		if (!ft_str_append(str, ft_c_str_borrow((t_str_slice []){}, "Velimir"))
		{
			// Error goes here
		}
	
	[-] Confusing to have both a pointer in and out for the borrow.
	[+] Can be used inline
		(but.. pretty long, so it might continue on the next line)

	Fifth variant: separate functions (Best one)

		if (!ft_str_append_c_str(str, "Velimir"))
		{
			// Error goes here
		}
		if (!ft_str_append_str(str, ponctuation))
		{
			// Error goes here
		}

	[+] Can be used inline
	[+] Concise
	[+] Compatible with both types
	[-] A bit of repetition in the implementation
*/

/******************************************************************************/
/* JOINING																	  */
/******************************************************************************/

typedef t_any_iterator		t_str_iterator;

/* Todo */
bool			ft_str_join_with_str(t_allocated_str *dest,
					t_str_iterator *iterator, t_str *any_sep);
bool			ft_str_join_with_c_str(t_allocated_str *dest,
					t_str_iterator *iterator, char *sep);
/* ---- */

# endif
#endif