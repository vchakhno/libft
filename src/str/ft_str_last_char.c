/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:07:04 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/17 13:19:16 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_str_last_char(const t_str str, char **out)
{
	char	*ptr;

	ptr = NULL;
	if (str.len)
		ptr = str.c_str + str.len - 1;
	if (out)
		*out = ptr;
	return (ptr);
}
