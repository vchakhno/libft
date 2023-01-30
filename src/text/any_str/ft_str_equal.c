/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:38:37 by velimir           #+#    #+#             */
/*   Updated: 2023/01/30 11:16:46 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/any_str_internal.h"
#include "libft/mem/mem.h"

bool	ft_str_equal(t_any_str *str1, t_any_str *str2)
{
	if (str1->len != str2->len)
		return (false);
	return (ft_mem_equal(str1->c_str, str2->c_str, str1->len));
}
