/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:00:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 19:59:49 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/char.h"
#include <stdbool.h>

void	ft_str_title(t_any_str *any_str)
{
	t_borrowed_str *const	str = any_str;
	t_u32					i;
	bool					is_prev_blank;

	i = 0;
	is_prev_blank = true;
	while (i < str->len)
	{
		if (is_prev_blank)
			str->c_str[i] = ft_char_to_upper(str->c_str[i]);
		else
			str->c_str[i] = ft_char_to_lower(str->c_str[i]);
		is_prev_blank = ft_char_is_blank(str->c_str[i]);
		i++;
	}
}
