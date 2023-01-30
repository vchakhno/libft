/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_startswith.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:38:37 by velimir           #+#    #+#             */
/*   Updated: 2023/01/30 10:17:05 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/any_str_internal.h"
#include "libft/mem.h"

bool	ft_str_startswith(t_any_str *str, t_any_str *prefix)
{
	if (prefix->len > str->len)
		return (false);
	return (ft_mem_equal(str->c_str, prefix->c_str, prefix->len));
}
