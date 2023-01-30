/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_borrow_c_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 08:06:50 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str_internal.h"
#include "libft_c_str.h"

t_str_slice	ft_str_borrow_c_str(const char *c_str)
{
	t_str_slice	str;

	str.c_str = (char *) c_str;
	str.len = ft_c_str_len(c_str);
	return (str);
}
