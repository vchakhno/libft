/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_str_borrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 16:38:06 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str.h"
#include "libft/bounds.h"

t_borrowed_str	ft_c_str_borrow(char *c_str)
{
	t_borrowed_str	str;

	str.c_str = c_str;
	str.len = ft_c_str_len(c_str);
	return (str);
}

t_borrowed_str	ft_c_str_borrow_slice__unchecked(
	char *c_str, t_u32 start, t_u32 len
) {
	t_borrowed_str	str;

	str.c_str = c_str + start;
	str.len = len;
	return (str);
}

t_borrowed_str	ft_c_str_borrow_slice(
	char *c_str, t_u32 start, t_u32 len
) {
	t_borrowed_str	str;
	t_u32			c_str_len;

	c_str_len = ft_c_str_len(c_str);
	start = ft_u32_min(start, c_str_len);
	str.c_str = c_str + start;
	str.len = ft_u32_min(len, c_str_len - start);
	return (str);
}
