/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_at_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:07:04 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 08:07:56 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str_internal.h"

char	*ft_str_at_char(t_str_slice *str, size_t index, char **out)
{
	char	*ptr;

	ptr = NULL;
	if (index < str.len)
		ptr = str.c_str + index;
	if (out)
		*out = ptr;
	return (ptr);
}
