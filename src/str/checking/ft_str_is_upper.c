/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:25:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/20 00:29:31 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/char.h"
#include <stdbool.h>

bool	ft_str_is_upper(t_any_str *str)
{
	size_t	i;

	i = 0;
	while (i < str->len)
	{
		if (!ft_char_is_upper(str->c_str[i]))
			return (false);
		i++;
	}
	return (true);
}
