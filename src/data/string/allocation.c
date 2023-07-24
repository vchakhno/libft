/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:57:19 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 05:49:20 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/string.h"
#include <stdlib.h>

void	ft_string_alloc_empty(t_string *string)
{
	string->c_str = NULL;
	string->len = 0;
	string->capacity = 0;
}

bool	ft_string_from_str(t_string *dest, t_str src)
{
	ft_string_alloc_empty(dest);
	return (ft_string_append_str(dest, src));
}

bool	ft_string_from_c_str(t_string *string, char *c_str)
{
	ft_string_alloc_empty(string);
	return (ft_string_append_c_str(string, c_str));
}

void	ft_string_free(t_string *string)
{
	free(string->c_str);
}
