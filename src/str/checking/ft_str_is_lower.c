/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:25:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 15:07:29 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internals.h"
#include "libft/fixed_types.h"
#include "libft/char.h"
#include <stdbool.h>

bool	ft_str_is_lower(t_any_str *str)
{
	t_u32	i;

	i = 0;
	while (i < str->len)
	{
		if (!ft_char_is_lower(str->c_str[i]))
			return (false);
		i++;
	}
	return (true);
}
