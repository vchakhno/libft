/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2022/10/17 17:49:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	ft_number_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_fill_itoa(char *str, int len, int n)
{
	int	first_part;

	first_part = ft_abs(n / 10);
	if (first_part)
		ft_fill_itoa(str, len - 1, first_part);
	str[len - 1] = ft_abs(n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_number_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		ft_fill_itoa(str + 1, len - 1, n);
	}
	else
	{
		ft_fill_itoa(str, len, n);
	}
	str[len] = '\0';
	return (str);
}
