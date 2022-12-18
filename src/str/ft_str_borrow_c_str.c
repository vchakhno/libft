/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_borrow_c_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/16 10:47:53 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

t_str	ft_str_borrow_c_str(const char *c_str, t_str *out)
{
	t_str	str;

	str.c_str = (char *) c_str;
	str.len = ft_c_str_len(c_str);
	str.capacity = 0;
	if (out)
		*out = str;
	return (str);
}
