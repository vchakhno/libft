/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 09:59:57 by vchakhno         ###   ########.fr       */
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

t_maybe_char_pos	ft_str_find_char(t_any_str *haystack, char c,
						t_find_char_options *options);

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