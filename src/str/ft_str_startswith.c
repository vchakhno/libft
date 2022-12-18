/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_startswith.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:38:37 by velimir           #+#    #+#             */
/*   Updated: 2022/12/09 05:28:29 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linft_str.h"
#include "linft_mem.h"

bool	ft_str_startswith(const t_str str, const t_str prefix)
{
	size_t	i;

	if (prefix.len > str.len)
		return (false);
	return (ft_mem_equals(str.c_str, prefix.c_str, prefix.len));
}
