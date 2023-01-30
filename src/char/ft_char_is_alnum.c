/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_is_alnum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:03:14 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/23 03:25:46 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_char.h"

bool	ft_char_is_alnum(char c)
{
	return (ft_char_is_alpha(c) || ft_char_is_digit(c));
}
