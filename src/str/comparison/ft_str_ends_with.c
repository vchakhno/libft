/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ends_with.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:26:05 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/20 01:33:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/mem/mem.h"
#include <stdbool.h>

bool	ft_str_ends_with_str(t_any_str *str, t_any_str *prefix)
{
	return (
		prefix->len <= str->len
		&& ft_mem_equal(
			str->c_str + str->len - prefix->len, prefix->c_str,
			prefix->len
		)
	);
}

bool	ft_str_ends_with_c_str(t_any_str *str, char *prefix)
{
	size_t	prefix_len;

	prefix_len = ft_c_str_len(prefix);
	return (
		prefix_len <= str->len
		&& ft_mem_equal(
			str->c_str + str->len - prefix_len, prefix,
			prefix_len
		)
	);
}
