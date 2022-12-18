/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:38:37 by velimir           #+#    #+#             */
/*   Updated: 2022/12/09 05:33:11 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linft_str.h"
#include "linft_math.h"

bool	ft_str_equal(const t_str str1, const t_str str2)
{
	size_t	i;

	if (str1.len != str2.len)
		return (false);
	return (ft_mem_equal(str1.c_str, str2.c_str, str1.len));
}
