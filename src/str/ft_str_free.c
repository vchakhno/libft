/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:56:17 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/19 14:04:05 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include <stdlib.h>

void	ft_str_free(t_str *str)
{
	str->len = 0;
	free(str->c_str);
	str->c_str = NULL;
	str->capacity = 0;
}
