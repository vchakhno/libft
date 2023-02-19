/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_borrowed_str_from_parts.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:21:04 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/18 21:36:15 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/borrowed_str_def.h"
#include <stddef.h>

t_borrowed_str	ft_borrowed_str_from_parts(char *c_str, size_t len)
{
	return ((t_borrowed_str){.c_str = c_str, .len = len});
}
