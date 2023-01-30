/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_borrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:00:39 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:20:43 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/any_str_internal.h"
#include "libft/text/borrowed_str.h"

t_borrowed_str	ft_str_borrow(t_any_str *str)
{
	return (ft_borrowed_str_from_parts(str->c_str, str->len));
}
