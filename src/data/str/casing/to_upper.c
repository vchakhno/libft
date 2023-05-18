/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_upper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:00:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:27:16 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str_internals.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/char.h"

void	ft_str_to_upper(t_any_str *str)
{
	t_u32	i;

	i = 0;
	while (i < str->len)
	{
		str->c_str[i] = ft_char_to_upper(str->c_str[i]);
		i++;
	}
}