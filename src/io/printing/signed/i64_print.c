/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i64_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/14 11:24:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/arithmetic/bounds.h"
#include "libft/io/printf.h"

bool	ft_i64_print(t_i64 value)
{
	return (ft_i64_oprint(value, ft_stdout()));
}

bool	ft_i64_println(t_i64 value)
{
	return (ft_i64_oprintln(value, ft_stdout()));
}

bool	ft_i64_oprint(t_i64 value, t_output *output)
{
	if (value < 0)
	{
		if (!ft_output_write(output, "-", 1))
			return (false);
	}
	if (value / 10)
	{
		if (!ft_i64_oprint(ft_i64_abs(value / 10), output))
			return (false);
	}
	return (
		ft_output_write(output, &(char){ft_i64_abs(value % 10) + '0'}, 1)
	);
}

bool	ft_i64_oprintln(t_i64 value, t_output *output)
{
	if (!ft_i64_oprint(value, output))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
