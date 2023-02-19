/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/18 23:10:48 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANY_STR_H
# define ANY_STR_H

# include "any_str_def.h"
# include "borrowed_str_def.h"
# include <stddef.h>
# include <stdbool.h>

/******************************************************************************/
/* COMPARISON																  */
/******************************************************************************/

int					ft_str_compare(t_any_str *str1, t_any_str *str2);
bool				ft_str_equal(t_any_str *str1, t_any_str *str2);
bool				ft_str_startswith(t_any_str *str, t_any_str *prefix);

/******************************************************************************/
/* SEARCH																	  */
/******************************************************************************/

typedef struct s_maybe_char_pos
{
	bool	exists;
	size_t	index;
	char	*ptr;
}	t_maybe_char_pos;

typedef struct s_find_char_options
{
	size_t	*out_index;
	char	**out_ptr;
	bool	reversed;
}	t_find_char_options;

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

bool				ft_str_find_char(t_any_str *haystack, char c,
						size_t *index);
bool				ft_str_find_char_rev(t_any_str *haystack, char c,
						size_t *index);

typedef struct s_maybe_str_pos
{
	bool			exists;
	size_t			index;
	t_borrowed_str	str;
}	t_maybe_str_pos;

typedef struct s_find_str_options
{
	size_t			*out_index;
	t_borrowed_str	*out_str;
	bool			reversed;
}	t_find_str_options;

t_maybe_str_pos		ft_str_find_str(
						t_any_str *haystack, t_any_str *needle,
						t_find_str_options *options);

/******************************************************************************/
/* TODO																		  */
/******************************************************************************/

// is*
// split to ostream

#endif