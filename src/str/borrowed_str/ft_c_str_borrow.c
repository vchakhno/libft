/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_str_borrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/19 03:11:32 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"

t_borrowed_str	ft_c_str_borrow(char *c_str)
{
	t_borrowed_str	str;

	str.c_str = c_str;
	str.len = ft_c_str_len(c_str);
	return (str);
}
