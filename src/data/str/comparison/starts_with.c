/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starts_with.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:26:05 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:29:27 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str_internals.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/mem/mem.h"
#include <stdbool.h>

bool	ft_str_starts_with_str(t_any_str *str, t_any_str *prefix)
{
	return (
		prefix->len <= str->len
		&& ft_mem_equal(str->c_str, prefix->c_str, prefix->len)
	);
}

bool	ft_str_starts_with_c_str(t_any_str *str, char *prefix)
{
	t_u32	prefix_len;

	prefix_len = ft_c_str_len(prefix);
	return (
		prefix_len <= str->len
		&& ft_mem_equal(str->c_str, prefix, prefix_len)
	);
}
