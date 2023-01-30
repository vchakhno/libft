/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:38:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:27:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

bool	ft_mem_chr(const void *ptr, size_t size, t_byte b, size_t *index)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((t_byte *) ptr)[i] == b)
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}
