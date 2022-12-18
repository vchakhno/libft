/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_index_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:19:16 by velimir           #+#    #+#             */
/*   Updated: 2022/12/09 09:29:52 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

bool	ft_str_index_char(const t_str str, char c, size_t *index)
{
	size_t	i;

	i = 0;
	while (i < str.len)
	{
		if (str.c_str[i] == c)
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}
