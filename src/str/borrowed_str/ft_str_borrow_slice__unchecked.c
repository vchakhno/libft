/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_borrow_slice__unchecked.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:00:39 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/19 03:11:56 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"

t_borrowed_str	ft_str_borrow_slice__unchecked(t_any_str *str,
	size_t start, size_t len
) {
	return (ft_borrowed_str_from_parts(str->c_str + start, len));
}
