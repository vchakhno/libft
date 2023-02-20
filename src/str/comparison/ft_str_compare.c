/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:13:29 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/20 01:19:11 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/mem/mem.h"
#include "libft/math.h"

int	ft_str_compare_str(t_any_str *str1, t_any_str *str2)
{
	return (
		ft_mem_compare(
			str1->c_str, str2->c_str,
			ft_math_min_size_t(str1->len, str2->len)
		)
	);
}

int	ft_str_compare_c_str(t_any_str *str1, char *str2)
{
	return (
		ft_mem_compare(
			str1->c_str, str2,
			ft_math_min_size_t(str1->len, ft_c_str_len(str2))
		)
	);
}
