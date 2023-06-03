/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alpha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:25:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:01:17 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/char.h"

bool	ft_str_is_alpha(t_any_str *any_str)
{
	t_borrowed_str *const	str = any_str;
	t_u32					i;

	i = 0;
	while (i < str->len)
	{
		if (!ft_char_is_alpha(str->c_str[i]))
			return (false);
		i++;
	}
	return (true);
}
