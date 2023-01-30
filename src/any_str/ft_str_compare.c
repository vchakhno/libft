/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:38:37 by velimir           #+#    #+#             */
/*   Updated: 2022/12/18 13:56:54 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_math.h"

int	ft_str_compare(const t_str str1, const t_str str2)
{
	size_t	i;

	i = 0;
	while (i < str1.len && i < str2.len)
	{
		if (str1.c_str[i] != str2.c_str[i])
			return (
				(unsigned char) str1.c_str[i] - (unsigned char) str2.c_str[i]
			);
		i++;
	}
	return (0);
}
