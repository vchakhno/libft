/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:41:10 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/09 03:58:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

int	ft_mem_compare(const void *ptr1, const void *ptr2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((t_byte *) ptr1)[i] != ((t_byte *) ptr2)[i])
			return (((t_byte *) ptr1)[i] - ((t_byte *) ptr2)[i]);
		i++;
	}
	return (0);
}
