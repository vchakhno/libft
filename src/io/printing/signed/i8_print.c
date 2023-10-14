/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i8_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/14 11:32:22 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/arithmetic/bounds.h"
#include "libft/io/printf.h"

bool	ft_i8_print(t_i8 value)
{
	return (ft_i8_oprint(value, ft_stdout()));
}

bool	ft_i8_println(t_i8 value)
{
	return (ft_i8_oprintln(value, ft_stdout()));
}

bool	ft_i8_oprint(t_i8 value, t_output *output)
{
	if (value < 0)
	{
		if (!ft_output_write(output, "-", 1))
			return (false);
	}
	if (value / 10)
	{
		if (!ft_i8_oprint(ft_i8_abs(value / 10), output))
			return (false);
	}
	return (
		ft_output_write(output, &(char){ft_i8_abs(value % 10) + '0'}, 1)
	);
}

bool	ft_i8_oprintln(t_i8 value, t_output *output)
{
	if (!ft_i8_oprint(value, output))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
