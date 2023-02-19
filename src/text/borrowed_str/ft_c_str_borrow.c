/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_str_borrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/18 21:36:42 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/borrowed_str.h"
#include "libft/text/c_str.h"

t_borrowed_str	ft_c_str_borrow(char *c_str)
{
	t_borrowed_str	str;

	str.c_str = c_str;
	str.len = ft_c_str_len(c_str);
	return (str);
}
