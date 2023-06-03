/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:57:19 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:37:25 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include <stdlib.h>

void	ft_str_alloc_empty(t_allocated_str *str)
{
	str->c_str = NULL;
	str->len = 0;
	str->capacity = 0;
}

bool	ft_str_dup_str(t_allocated_str *dest, t_any_str *any_src)
{
	ft_str_alloc_empty(dest);
	return (ft_str_append_str(dest, any_src));
}

bool	ft_str_dup_c_str(t_allocated_str *str, char *c_str)
{
	ft_str_alloc_empty(str);
	return (ft_str_append_c_str(str, c_str));
}

void	ft_str_free(t_allocated_str *str)
{
	free(str->c_str);
}
