/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_str_borrow_slice__unchecked.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:03:58 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/19 03:11:20 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/str/str.h"

t_borrowed_str	ft_c_str_borrow_slice__unchecked(char *c_str,
	size_t start, size_t len
) {
	return (ft_borrowed_str_from_parts(c_str + start, len));
}
