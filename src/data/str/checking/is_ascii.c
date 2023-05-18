/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:25:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:28:00 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str_internals.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/char.h"

bool	ft_str_is_ascii(t_any_str *str)
{
	t_u32	i;

	i = 0;
	while (i < str->len)
	{
		if (!ft_char_is_ascii(str->c_str[i]))
			return (false);
		i++;
	}
	return (true);
}
