/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 11:16:46 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/str.h"
#include "libft/mem/mem.h"
#include <stdlib.h>

static size_t	ft_str_joined_len(
					const t_str *strs, size_t size,
					const t_str delimiter);

bool	ft_str_join(
	t_str *joined,
	const t_str *strs, size_t size,
	t_str delimiter)
{
	size_t	i;

	joined->len = 0;
	joined->capacity = ft_alloc_capacity(
			ft_str_joined_len(strs, size, delimiter) + 1);
	joined->c_str = malloc(sizeof(char) * joined->capacity);
	if (!joined->c_str)
		return (false);
	i = 0;
	while (i < size)
	{
		ft_c_str_ncopy(joined->c_str, strs[i].c_str, strs[i].len);
		joined->len += strs[i].len;
		if (i < size - 1)
		{
			ft_c_str_ncopy(joined->c_str, delimiter.c_str, delimiter.len);
			joined->len += delimiter.len;
		}
		i++;
	}
	return (true);
}

static size_t	ft_str_joined_len(
	const t_str *strs, size_t size,
	const t_str delimiter)
{
	size_t	len;
	size_t	i;

	if (!size)
		return (0);
	len = delimiter.len * (size - 1);
	i = 0;
	while (i < size)
	{
		len += strs[i].len;
		i++;
	}
	return (len);
}
