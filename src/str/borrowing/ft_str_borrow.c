/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_borrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:00:39 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 16:38:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internals.h"
#include "libft/fixed_types.h"
#include "libft/bounds.h"

t_borrowed_str	ft_str_borrow(t_any_str *str)
{
	return (*str);
}

t_borrowed_str	ft_str_borrow_slice__unchecked(
	t_any_str *str, t_u32 start, t_u32 len
) {
	t_borrowed_str	borrowed;

	borrowed.c_str = str->c_str + start;
	borrowed.len = len;
	return (borrowed);
}

t_borrowed_str	ft_str_borrow_slice(t_any_str *str, t_u32 start, t_u32 len)
{
	t_borrowed_str	borrowed;

	start = ft_u32_min(start, str->len);
	borrowed.c_str = str->c_str + start;
	borrowed.len = ft_u32_min(len, str->len - start);
	return (borrowed);
}
