/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:48:26 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stdbool.h>
# include "libft/arithmetic/fixed_types.h"
# include "libft/data/iterator.h"
# include "libft/io/ostream/ostream.h"

typedef struct s_borrowed_str
{
	char	*c_str;
	t_u32	len;
}	t_borrowed_str;

typedef struct s_allocated_str
{
	char	*c_str;
	t_u32	len;
	t_u32	capacity;
}	t_allocated_str;

typedef t_allocated_str		t_str;
typedef t_borrowed_str		t_str_slice;
typedef void				t_any_str;

/******************************************************************************/
/* C_STR																	  */
/******************************************************************************/

t_u32			ft_c_str_len(const char *c_str);
void			ft_c_str_ncopy(char *dest, const char *src, t_u32 len);

/******************************************************************************/
/* PRINTING																	  */
/******************************************************************************/

bool			ft_c_str_print(char *c_str);
bool			ft_c_str_println(char *c_str);
bool			ft_c_str_oprint(t_any_str_ostream *stream, char *c_str);
bool			ft_c_str_oprintln(t_any_str_ostream *stream, char *c_str);

bool			ft_str_print(t_any_str *any_str);
bool			ft_str_println(t_any_str *any_str);
bool			ft_str_oprint(t_any_str_ostream *stream, t_any_str *any_str);
bool			ft_str_oprintln(t_any_str_ostream *stream, t_any_str *any_str);

/******************************************************************************/
/* BORROWING																  */
/******************************************************************************/

t_borrowed_str	ft_borrowed_str_from_parts(char *c_str, t_u32 len);
t_borrowed_str	ft_c_str_borrow(char *c_str);
t_borrowed_str	ft_c_str_borrow_slice__unchecked(char *c_str,
					t_u32 start, t_u32 len);
t_borrowed_str	ft_c_str_borrow_slice(char *c_str,
					t_u32 start, t_u32 len);
t_borrowed_str	ft_str_borrow(t_any_str *any_str);
t_borrowed_str	ft_str_borrow_slice__unchecked(t_any_str *any_str,
					t_u32 start, t_u32 len);
t_borrowed_str	ft_str_borrow_slice(t_any_str *any_str,
					t_u32 start, t_u32 len);

/******************************************************************************/
/* CHECKING																	  */
/******************************************************************************/

bool			ft_str_is_alnum(t_any_str *any_str);
bool			ft_str_is_alpha(t_any_str *any_str);
bool			ft_str_is_ascii(t_any_str *any_str);
bool			ft_str_is_blank(t_any_str *any_str);
bool			ft_str_is_digit(t_any_str *any_str);
bool			ft_str_is_lower(t_any_str *any_str);
bool			ft_str_is_print(t_any_str *any_str);
bool			ft_str_is_upper(t_any_str *any_str);

/******************************************************************************/
/* COMPARISON																  */
/******************************************************************************/

t_i32			ft_str_compare_c_str(t_any_str *any_str1, char *str2);
bool			ft_str_equal_c_str(t_any_str *any_str1, char *str2);
bool			ft_str_starts_with_c_str(t_any_str *any_str, char *prefix);
bool			ft_str_ends_with_c_str(t_any_str *any_str, char *suffix);

t_i32			ft_str_compare_str(t_any_str *any_str1, t_any_str *any_str2);
bool			ft_str_equal_str(t_any_str *any_str1, t_any_str *any_str2);
bool			ft_str_starts_with_str(
					t_any_str *any_str, t_any_str *any_prefix);
bool			ft_str_ends_with_str(t_any_str *any_str, t_any_str *any_suffix);

/******************************************************************************/
/* SEARCH																	  */
/******************************************************************************/

/*
	Could be prototyped in a lot of ways:
	
	1)
	Prototype:
		st_u32	ft_str_find_char(t_any_str *haystack, char c);

	Usage:
		st_u32	index;

		index = ft_str_find_char(str, c);
		if (index == -1)
		{
			// Error goes here
		}

	Notes:
		[+] Pretty classic.
		[-] Separates the call out of the if.
		[-] Doesn't give a pointer.
		[+] Can be used inline if the result is known to be true.
	
	2)
	Prototype:
		t_maybe_char_pos	ft_str_find_char(t_any_str *haystack, char c);

	Usage:
		t_maybe_char_pos	maybe_pos;

		maybe_pos = ft_str_find_char(str, c);
		if (!maybe_pos.exists)
		{
			// Error goes here
		}
	
	Notes:
		[-] Needs to use a custom type.
		[+] Can be used inline if the result is known to be true.
		[+] Gives out a pointer too.
		[-] Separates the call out of the if.

	3) (Best one for now)
	Prototype:
		bool	ft_str_find_char(t_any_str *haystack, char c, t_u32 *index);
	
	Usage:
		t_u32	index;
		
		if (!ft_str_find_char(str, c, &index))
		{
			// Error goes here
		}
	
	Notes:
		[+] Coherent with the rest of the library.
		[+] Merges with the if
		[-] Doesn't give a pointer
		[-] Cannot be used inline

	And other experimental prototypes.
	(?) t_find_char_option that takes optionnal pointers
	(?) Callback that takes an int
*/

bool			ft_str_contains_char(t_any_str *any_haystack, char c);
bool			ft_str_find_char(t_any_str *any_haystack, char c,
					t_u32 *index);
bool			ft_str_rfind_char(t_any_str *any_haystack, char c,
					t_u32 *index);
t_u32			ft_str_count_char(t_any_str *any_haystack, char c);

bool			ft_str_contains_str(
					t_any_str *any_haystack, t_any_str *any_needle);
bool			ft_str_find_str(t_any_str *any_haystack, t_any_str *any_needle,
					t_u32 *index);
bool			ft_str_rfind_str(
					t_any_str *any_haystack, t_any_str *any_needle,
					t_u32 *index);
t_u32			ft_str_count_str(
					t_any_str *any_haystack, t_any_str *any_needle);

bool			ft_str_contains_c_str(t_any_str *any_haystack, char *needle);
bool			ft_str_find_c_str(t_any_str *any_haystack, char *needle,
					t_u32 *index);
bool			ft_str_rfind_c_str(t_any_str *any_haystack, char *needle,
					t_u32 *index);
t_u32			ft_str_count_c_str(t_any_str *any_haystack, char *needle);

/******************************************************************************/
/* SPLITTING																  */
/******************************************************************************/

typedef struct s_str_split_iterator
{
	t_iterator_base	base;
	t_borrowed_str	remaining;
	t_borrowed_str	delim;
}	t_str_split_iterator;

void			ft_str_split_by_str(t_any_str *any_str, t_any_str *any_delim,
					t_str_split_iterator *iterator);
void			ft_str_split_by_c_str(t_any_str *any_str, char *delim,
					t_str_split_iterator *iterator);

void			ft_str_rsplit_by_str(t_any_str *any_str, t_any_str *any_delim,
					t_str_split_iterator *iterator);
void			ft_str_rsplit_by_c_str(t_any_str *any_str, char *delim,
					t_str_split_iterator *iterator);

/*
	Example usage:

		t_str_split_iterator	iterator;
		t_str_slice				word;
		
		ft_str_split_by_c_str(str, ", ", &iterator);
		while (ft_iterator_next(&iterator, &word))
		{
			
		}

	Example 2:
	
		t_str_split_iterator	iterator;
		t_vec					words;

		ft_str_split_by_c_str(str, ", ", &iterator);
		if (!ft_vec_collect(&words, sizeof(t_str_slice), &iterator))
		{
			// Error goes here
		}
		// ...
		ft_vec_free(&words);
*/

/******************************************************************************/
/* CASING																	  */
/******************************************************************************/

void			ft_str_to_upper(t_any_str *any_str);
void			ft_str_to_lower(t_any_str *any_str);
void			ft_str_title(t_any_str *any_str);
void			ft_str_swap_case(t_any_str *any_str);

/******************************************************************************/
/* ALLOCATION																  */
/******************************************************************************/

void			ft_str_alloc_empty(t_allocated_str *str);
bool			ft_str_dup_c_str(t_allocated_str *str, char *c_str)
				__attribute__((warn_unused_result));
bool			ft_str_dup_str(t_allocated_str *dest, t_any_str *any_src)
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

bool			ft_str_append_str(t_allocated_str *str, t_any_str *any_suffix);
bool			ft_str_prepend_str(t_allocated_str *str, t_any_str *any_prefix);
bool			ft_str_insert_str(t_allocated_str *str,
					t_u32 index, t_any_str *any_inserted);

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
					t_any_str *any_prefix);
bool			ft_str_remove_c_str_suffix(t_allocated_str *str, char *suffix);
bool			ft_str_remove_str_suffix(t_allocated_str *str,
					t_any_str *any_suffix);

/******************************************************************************/
/* FORMATTING																  */
/******************************************************************************/

/* Todo */
bool			ft_str_replace(t_allocated_str *str,
					t_any_str *any_old, t_any_str *any_new);
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

typedef t_any_iterator		t_any_str_iterator;

/* Todo */
bool			ft_str_join_with_str(t_allocated_str *dest,
					t_any_str_iterator *iterator, t_any_str *any_sep);
bool			ft_str_join_with_c_str(t_allocated_str *dest,
					t_any_str_iterator *iterator, char *sep);
/* ---- */

#endif