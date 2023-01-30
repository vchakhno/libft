/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:40:36 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:27:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

void	ft_mem_zero(void *ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((t_byte *) ptr)[i] = 0;
		i++;
	}
}
