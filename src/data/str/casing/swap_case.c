/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:00:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 19:59:41 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include "libft/arithmetic/fixed_types.h"
#include "libft/data/char.h"

void	ft_str_swap_case(t_any_str *any_str)
{
	t_borrowed_str *const	str = any_str;
	t_u32					i;

	i = 0;
	while (i < str->len)
	{
		str->c_str[i] = ft_char_swap_case(str->c_str[i]);
		i++;
	}
}
