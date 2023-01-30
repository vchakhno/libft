/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_str_borrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 09:55:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/borrowed_str.h"
#include "libft/text/c_str.h"

t_borrowed_str	ft_c_str_borrow(const char *c_str)
{
	t_borrowed_str	str;

	str.c_str = (char *) c_str;
	str.len = ft_c_str_len(c_str);
	return (str);
}
