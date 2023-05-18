/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:39:46 by velimir           #+#    #+#             */
/*   Updated: 2023/02/19 01:08:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_char_to_upper(char c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}