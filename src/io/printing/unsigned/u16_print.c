/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u16_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/14 11:26:12 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/io/printf.h"

bool	ft_u16_print(t_u16 value)
{
	return (ft_u16_oprint(value, ft_stdout()));
}

bool	ft_u16_println(t_u16 value)
{
	return (ft_u16_oprintln(value, ft_stdout()));
}

bool	ft_u16_oprint(t_u16 value, t_output *output)
{
	if (value >= 10)
	{
		if (!ft_u16_oprint(value / 10, output))
			return (false);
	}
	return (ft_output_write(output, &(char){value % 10 + '0'}, 1));
}

bool	ft_u16_oprintln(t_u16 value, t_output *output)
{
	if (!ft_u16_oprint(value, output))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
