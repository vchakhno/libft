/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_borrowed_str_from_parts.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:21:04 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 14:41:15 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str.h"
#include "libft/fixed_types.h"

t_borrowed_str	ft_borrowed_str_from_parts(char *c_str, t_u32 len)
{
	return ((t_borrowed_str){.c_str = c_str, .len = len});
}
