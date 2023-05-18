/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borrowed_str_from_parts.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:21:04 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:24:50 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"

t_borrowed_str	ft_borrowed_str_from_parts(char *c_str, t_u32 len)
{
	return ((t_borrowed_str){.c_str = c_str, .len = len});
}
