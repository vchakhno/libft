/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_set_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:17:25 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/17 13:22:36 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

bool	ft_str_set_char(t_str *str, char c, size_t index)
{
	if (index >= str->len)
		return (false);
	str->c_str[index] = c;
	return (true);
}
