/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 02:00:19 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/18 11:22:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include <stdlib.h>

bool	ft_str_reserve_exact(t_str *str, size_t capacity)
{
	t_str	old;

	if (capacity <= str->capacity)
		return (true);
	old = *str;
	str->capacity = capacity;
	str->c_str = malloc(sizeof(char) * str->capacity);
	if (str->c_str)
		ft_c_str_ncopy(str->c_str, old.c_str, str->len);
	ft_str_free(&old);
	return (str->c_str);
}
