/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:19:16 by velimir           #+#    #+#             */
/*   Updated: 2023/01/30 11:16:46 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/any_str_internal.h"
#include "libft/text/borrowed_str.h"
#include "libft/mem/mem.h"

static bool	ft_str_find_str_forw(t_any_str *haystack, t_any_str *needle,
				size_t *index);
static bool	ft_str_find_str_backw(t_any_str *haystack, t_any_str *needle,
				size_t *index);

typedef bool	(*t_str_finder)(t_any_str *haystack, t_any_str *needle,
	size_t *index);

t_maybe_str_pos	ft_str_find_str(
	t_any_str *haystack, t_any_str *needle,
	t_find_str_options *options
) {
	size_t			index;
	t_borrowed_str	str;

	if (needle->len > haystack->len
		|| !(t_str_finder []){
		ft_str_find_str_forw, ft_str_find_str_backw
	}[options && options->reversed](haystack, needle, &index))
		return ((t_maybe_str_pos){.exists = false});
	str = ft_borrowed_str_from_parts(haystack->c_str + index, needle->len);
	if (options && options->out_index)
		*options->out_index = index;
	if (options && options->out_str)
		*options->out_str = str;
	return ((t_maybe_str_pos){
		.exists = true, .index = index, .str = str
	});
}

static bool	ft_str_find_str_forw(
	t_any_str *haystack, t_any_str *needle,
	size_t *index
) {
	size_t	i;

	i = 0;
	while (i < haystack->len - needle->len)
	{
		if (ft_mem_equal(haystack->c_str + i, needle->c_str, needle->len))
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	ft_str_find_str_backw(
	t_any_str *haystack, t_any_str *needle,
	size_t *index
) {
	size_t	i;

	i = haystack->len - needle->len;
	while (i > 0)
	{
		if (ft_mem_equal(haystack->c_str + i - 1, needle->c_str, needle->len))
		{
			*index = i - 1;
			return (true);
		}
		i--;
	}
	return (false);
}
