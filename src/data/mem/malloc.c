/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 07:42:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:22:51 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/mem/mem_internals.h"
#include <stdlib.h>

bool	ft_mem_malloc(t_ptr *ptr, t_u32 size)
{
	*ptr = malloc(size);
	return (*ptr);
}
