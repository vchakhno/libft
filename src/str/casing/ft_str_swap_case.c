/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_swap_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:00:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 14:58:37 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internals.h"
#include "libft/fixed_types.h"
#include "libft/char.h"

void	ft_str_swap_case(t_any_str *str)
{
	t_u32	i;

	i = 0;
	while (i < str->len)
	{
		str->c_str[i] = ft_char_swap_case(str->c_str[i]);
		i++;
	}
}
