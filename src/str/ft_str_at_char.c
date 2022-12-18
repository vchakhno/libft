/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:07:04 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/17 13:18:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_str_at_char(const t_str str, size_t index, char **out)
{
	char	*ptr;

	ptr = NULL;
	if (index < str.len)
		ptr = str.c_str + index;
	if (out)
		*out = ptr;
	return (ptr);
}
