/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 07:42:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 23:07:17 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem_internals.h"
#include <stdlib.h>

bool	ft_mem_malloc(t_ptr *ptr, t_u32 size)
{
	*ptr = malloc(size);
	return (*ptr);
}
