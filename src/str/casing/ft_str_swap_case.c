/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_swap_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:00:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/22 07:04:40 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include "libft/char.h"

static char	ft_swap_case(char c)
{
	if ('A' <= c && c <= 'Z')
		return (c - 'A' + 'a');
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'Z');
	return (c);
}

void	ft_str_swap_case(t_any_str *str)
{
	size_t	i;

	i = 0;
	while (i < str->len)
	{
		str->c_str[i] = ft_swap_case(str->c_str[i]);
		i++;
	}
}
