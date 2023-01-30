/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:38:37 by velimir           #+#    #+#             */
/*   Updated: 2023/01/30 10:13:23 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/any_str_internal.h"

int	ft_str_compare(t_any_str *str1, t_any_str *str2)
{
	size_t	i;

	i = 0;
	while (i < str1->len && i < str2->len)
	{
		if (str1->c_str[i] != str2->c_str[i])
			return (
				(unsigned char) str1->c_str[i] - (unsigned char) str2->c_str[i]
			);
		i++;
	}
	return (0);
}
