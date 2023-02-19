/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/19 03:03:34 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stddef.h>
# include <stdbool.h>

# ifndef STR_INTERNAL_TYPES_H
#  include "str_types.h"
# endif

// C str
size_t			ft_c_str_len(const char *c_str);
void			ft_c_str_ncopy(char *dest, const char *src, size_t len);
bool			ft_c_str_ndup__unchecked(char **dest, const char *src,
					size_t len, size_t capacity);

// borrowed str
t_borrowed_str	ft_borrowed_str_from_parts(char *c_str, size_t len);
t_borrowed_str	ft_c_str_borrow(char *c_str);
t_borrowed_str	ft_c_str_borrow_slice__unchecked(char *c_str,
					size_t start, size_t len);
t_borrowed_str	ft_str_borrow(t_any_str *str);
t_borrowed_str	ft_str_borrow_slice__unchecked(t_any_str *str,
					size_t start, size_t len);
t_borrowed_str	ft_str_borrow_slice(t_any_str *str,
					size_t start, size_t len);

/******************************************************************************/
/* COMPARISON																  */
/******************************************************************************/

int				ft_str_compare(t_any_str *str1, t_any_str *str2);
bool			ft_str_equal(t_any_str *str1, t_any_str *str2);
bool			ft_str_startswith(t_any_str *str, t_any_str *prefix);

/******************************************************************************/
/* SEARCH																	  */
/******************************************************************************/

/*
	Could be prototyped in a lot of ways:
	
	1)
	Prototype:
		ssize_t	ft_str_find_char(t_any_str *haystack, char c);

	Usage:
		ssize_t	index;

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
		bool	ft_str_find_char(t_any_str *haystack, char c, size_t *index);
	
	Usage:
		size_t	index;
		
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

bool			ft_str_find_char(t_any_str *haystack, char c,
					size_t *index);
bool			ft_str_find_char_rev(t_any_str *haystack, char c,
					size_t *index);
bool			ft_str_find_str(t_any_str *haystack, t_any_str *needle,
					size_t *index);
bool			ft_str_find_str_rev(t_any_str *haystack, t_any_str *needle,
					size_t *index);

/******************************************************************************/
/* TODO																		  */
/******************************************************************************/

// is*
// split to ostream

#endif