/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ends_with.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:26:05 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:47:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/mem.h"
#include <stdbool.h>

bool	ft_str_ends_with_str(t_any_str *any_str, t_any_str *any_prefix)
{
	t_borrowed_str *const	str = any_str;
	t_borrowed_str *const	prefix = any_prefix;

	return (
		prefix->len <= str->len
		&& ft_mem_equal(
			str->c_str + str->len - prefix->len, prefix->c_str,
			prefix->len
		)
	);
}

bool	ft_str_ends_with_c_str(t_any_str *any_str, char *prefix)
{
	t_borrowed_str *const	str = any_str;
	t_u32					prefix_len;

	prefix_len = ft_c_str_len(prefix);
	return (
		prefix_len <= str->len
		&& ft_mem_equal(
			str->c_str + str->len - prefix_len, prefix,
			prefix_len
		)
	);
}
