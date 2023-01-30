/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_get_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:46:50 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/16 11:58:58 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

t_maybe_char	ft_str_get_char(const t_str str, size_t index, char *out)
{
	char	c;

	if (index >= str.len)
		return ((t_maybe_char){.exists = false});
	c = str.c_str[index];
	if (out)
		*out = c;
	return ((t_maybe_char){.exists = true, .c = c});
}