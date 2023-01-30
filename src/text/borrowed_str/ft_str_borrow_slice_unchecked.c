/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_borrow_slice_unchecked.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:00:39 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:18:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/any_str_internal.h"
#include "libft/text/borrowed_str.h"

t_borrowed_str	ft_str_borrow_slice__unchecked(t_any_str *str,
	size_t start, size_t len
) {
	return (ft_borrowed_str_from_parts(str->c_str + start, len));
}
