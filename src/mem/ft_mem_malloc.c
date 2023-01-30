/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 07:42:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/18 15:17:46 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"
#include <stdlib.h>

bool	ft_mem_malloc(void *dest, size_t size)
{
	*(void **)dest = malloc(size);
	return (*(void **)dest);
}
