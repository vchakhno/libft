/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:18:09 by vchakhno          #+#    #+#             */
/*   Updated: 2022/10/16 04:00:31 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

static bool	ft_is_whitespace(char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

int	ft_atoi(const char *str)
{
	int	value;
	int	sign;

	while (ft_is_whitespace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	value = 0;
	while ('0' <= *str && *str <= '9')
	{
		value = value * 10 + *str - '0';
		str++;
	}
	return (value * sign);
}
