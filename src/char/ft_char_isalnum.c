/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:03:14 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/08 06:50:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_char.h"

bool	ft_char_isalnum(int c)
{
	return (ft_char_isalpha(c) || ft_char_isdigit(c));
}
