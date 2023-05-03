/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_title.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:00:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 14:59:29 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internals.h"
#include "libft/fixed_types.h"
#include "libft/char.h"
#include <stdbool.h>

void	ft_str_title(t_any_str *str)
{
	t_u32	i;
	bool	is_prev_blank;

	i = 0;
	is_prev_blank = true;
	while (i < str->len)
	{
		if (is_prev_blank)
			str->c_str[i] = ft_char_to_upper(str->c_str[i]);
		else
			str->c_str[i] = ft_char_to_upper(str->c_str[i]);
		is_prev_blank = ft_char_is_blank(str->c_str[i]);
		i++;
	}
}
