/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borrowed_str_from_parts.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:21:04 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 04:47:08 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str.h"

t_str	ft_str_from(char *c_str, t_u32 len)
{
	return ((t_str){.c_str = c_str, .len = len});
}

t_str	ft_str_from_c_str(char *c_str)
{
	return ((t_str){.c_str = c_str, .len = ft_c_str_len(c_str)});
}
