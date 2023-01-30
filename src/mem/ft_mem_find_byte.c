/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_find_byte.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:38:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:57:11 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

t_maybe_byte_pos	*ft_mem_find_byte(const void *ptr, size_t size, t_byte b,
	t_find_byte_options *options)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((t_byte *) ptr)[i] == b)
		{
			if (options && options->out_index)
				*options->out_index = i;
			if (options && options->out_ptr)
				*options->out_ptr = (t_byte *) ptr + i;
			return ((void *) ptr + i);
		}
		i++;
	}
	return (NULL);
}
