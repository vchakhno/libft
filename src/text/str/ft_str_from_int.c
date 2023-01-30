/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_from_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:52:42 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:27:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/str.h"
#include "libft/mem.h"
#include "libft/math.h"
#include <stdlib.h>

static int	ft_num_len(int n)
{
	int	len;

	len = n <= 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	ft_fill_number(t_str *str, int n)
{
	int	i;

	str->c_str[str->len] = '\0';
	if (n < 0)
		str->c_str[0] = '-';
	i = str->len - 1;
	while (n)
	{
		str->c_str[i] = ft_abs(n % 10) + '0';
		i--;
		n /= 10;
	}
}

bool	ft_str_from_int(t_str *str, int n)
{
	str->len = ft_num_len(n);
	str->capacity = ft_alloc_capacity(str->len + 1);
	if (!ft_mem_malloc(&str->c_str, sizeof(char) * str->capacity))
		return (false);
	ft_fill_number(str, n);
	return (true);
}
