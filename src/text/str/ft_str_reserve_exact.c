/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reserve_exact.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 02:00:19 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 11:16:46 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/text/str.h"
#include "libft/mem/mem.h"
#include "libft_c_str.h"

bool	ft_str_reserve_exact(t_str *str, size_t capacity)
{
	t_str	old;

	if (capacity <= str->capacity)
		return (true);
	old = *str;
	str->capacity = capacity;
	if (ft_mem_malloc(&str->c_str, sizeof(char) * str->capacity))
		ft_c_str_ncopy(str->c_str, old.c_str, str->len);
	ft_str_free(&old);
	return (str->c_str);
}
