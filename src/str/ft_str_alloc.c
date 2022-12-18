/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/16 10:21:11 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_math.h"
#include <stdlib.h>

bool	ft_str_alloc(t_str *str, const char *c_str, size_t len)
{
	str->len = len;
	str->capacity = ft_alloc_capacity(str->len + 1);
	str->c_str = malloc(sizeof(char) * str->capacity);
	ft_c_str_ncopy(str->c_str, c_str, len);
	return (str->c_str);
}
