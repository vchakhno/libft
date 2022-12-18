/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_str_ncopy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 02:38:23 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/18 11:34:29 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_mem.h"

void	ft_c_str_ncopy(char *dest, const char *src, size_t len)
{
	ft_mem_copy(dest, src, len);
	dest[len] = '\0';
}
