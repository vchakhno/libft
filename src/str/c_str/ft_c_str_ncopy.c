/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_str_ncopy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 02:38:23 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 14:52:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem/mem.h"
#include "libft/fixed_types.h"

void	ft_c_str_ncopy(char *dest, const char *src, t_u32 len)
{
	ft_mem_copy(dest, src, len);
	dest[len] = '\0';
}
