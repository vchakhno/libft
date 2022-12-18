/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:18:09 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/08 06:55:26 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

int	ft_int_fromstr(const t_str str)
{
	int		value;
	int		sign;
	size_t	i;

	i = 0;
	while (ft_char_iswhitespace(str.c_str[i]))
		i++;
	sign = 1;
	if (str.c_str[i] == '+' || str.c_str[i] == '-')
	{
		if (str.c_str[i] == '-')
			sign *= -1;
		i++;
	}
	value = 0;
	while ('0' <= str.c_str[i] && str.c_str[i] <= '9')
	{
		value = value * 10 + str.c_str[i] - '0';
		str++;
	}
	return (value * sign);
}
