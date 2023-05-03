/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_strip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:35:00 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 16:36:12 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str.h"
#include "libft/mem/mem.h"

bool	ft_str_strip(t_allocated_str *str, char *stripped)
{
	ft_str_rstrip(str, stripped);
	ft_str_lstrip(str, stripped);
	return (true);
}
