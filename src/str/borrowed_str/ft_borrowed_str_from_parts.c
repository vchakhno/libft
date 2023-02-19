/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_borrowed_str_from_parts.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:21:04 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/19 03:10:47 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str_internal_types.h"
#include <stddef.h>

t_borrowed_str	ft_borrowed_str_from_parts(char *c_str, size_t len)
{
	return ((t_borrowed_str){.c_str = c_str, .len = len});
}
