/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:38:37 by velimir           #+#    #+#             */
/*   Updated: 2022/12/09 03:53:25 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linft_str.h"
#include "linft_math.h"

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
