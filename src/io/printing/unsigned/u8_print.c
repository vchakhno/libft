/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u8_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 03:59:56 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/io/printf.h"

bool	ft_u8_print(t_u8 value)
{
	return (ft_u8_oprint(ft_stdout(), value));
}

bool	ft_u8_println(t_u8 value)
{
	return (ft_u8_oprintln(ft_stdout(), value));
}

bool	ft_u8_oprint(t_output *output, t_u8 value)
{
	if (value >= 10)
	{
		if (!ft_u8_oprint(output, value / 10))
			return (false);
	}
	return (ft_output_write(output, &(char){value % 10 + '0'}, 1));
}

bool	ft_u8_oprintln(t_output *output, t_u8 value)
{
	if (!ft_u8_oprint(output, value))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
