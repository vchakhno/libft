/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_borrow_slice.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:00:39 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/19 03:12:04 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"
#include "libft/math.h"

t_borrowed_str	ft_str_borrow_slice(t_any_str *str, size_t start, size_t len
) {
	start = ft_math_min_size_t(start, str->len);
	len = ft_math_min_size_t(len, str->len - start);
	return (ft_borrowed_str_from_parts(str->c_str + start, len));
}
