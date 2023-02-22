/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_title.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:00:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/22 07:06:28 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/char.h"
#include <stdbool.h>

void	ft_str_title(t_any_str *str)
{
	size_t	i;
	bool	is_last_space;

	i = 0;
	is_last_space = true;
	while (i < str->len)
	{
		if (is_last_space)
			str->c_str[i] = ft_char_to_upper(str->c_str[i]);
		else
			str->c_str[i] = ft_char_to_upper(str->c_str[i]);
		is_last_space = ft_char_is_blank(str->c_str[i]);
		i++;
	}
}
