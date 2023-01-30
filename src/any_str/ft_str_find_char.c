/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:19:16 by velimir           #+#    #+#             */
/*   Updated: 2022/12/22 03:46:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

static bool	ft_str_find_char_forw(const t_str haystack, char c, size_t *index);
static bool	ft_str_find_char_backw(const t_str haystack, char c, size_t *index);
typedef bool	(*t_char_finder)(const t_str haystack, char c, size_t *index);

t_maybe_char_pos	ft_str_find_char(
	const t_str haystack, char c,
	t_find_char_options *options
) {
	size_t	index;

	if (!(t_char_finder []){
		ft_str_find_char_forw, ft_str_find_char_backw
	}[options && options->reversed](haystack, c, &index))
		return ((t_maybe_char_pos){.exists = false});
	if (options && options->out_index)
		*options->out_index = index;
	if (options && options->out_ptr)
		*options->out_ptr = haystack.c_str + index;
	return ((t_maybe_char_pos){
		.exists = true,
		.index = index, .ptr = haystack.c_str + index
	});
}

static bool	ft_str_find_char_forw(const t_str haystack, char c, size_t *index)
{
	size_t	i;

	i = 0;
	while (i < haystack.len)
	{
		if (haystack.c_str[i] == c)
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	ft_str_find_char_backw(const t_str haystack, char c, size_t *index)
{
	size_t	i;

	i = haystack.len;
	while (i > 0)
	{
		if (haystack.c_str[i - 1] == c)
		{
			*index = i - 1;
			return (true);
		}
		i--;
	}
	return (false);
}
