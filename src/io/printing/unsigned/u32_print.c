/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u32_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/14 11:26:44 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/io/printf.h"

bool	ft_u32_print(t_u32 value)
{
	return (ft_u32_oprint(value, ft_stdout()));
}

bool	ft_u32_println(t_u32 value)
{
	return (ft_u32_oprintln(value, ft_stdout()));
}

bool	ft_u32_oprint(t_u32 value, t_output *output)
{
	if (value >= 10)
	{
		if (!ft_u32_oprint(value / 10, output))
			return (false);
	}
	return (ft_output_write(output, &(char){value % 10 + '0'}, 1));
}

bool	ft_u32_oprintln(t_u32 value, t_output *output)
{
	if (!ft_u32_oprint(value, output))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
