/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_fromstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:18:09 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 08:27:32 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/str.h"

int	ft_int_fromstr(const t_str str)
{
	int		value;
	int		sign;
	size_t	i;

	i = 0;
	while (ft_char_is_whitespace(str.c_str[i]))
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
