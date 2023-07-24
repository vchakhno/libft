/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u32_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 03:59:57 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing.h"
#include "libft/io/printf.h"

bool	ft_u32_print(t_u32 value)
{
	return (ft_u32_oprint(ft_stdout(), value));
}

bool	ft_u32_println(t_u32 value)
{
	return (ft_u32_oprintln(ft_stdout(), value));
}

bool	ft_u32_oprint(t_output *output, t_u32 value)
{
	if (value >= 10)
	{
		if (!ft_u32_oprint(output, value / 10))
			return (false);
	}
	return (ft_output_write(output, &(char){value % 10 + '0'}, 1));
}

bool	ft_u32_oprintln(t_output *output, t_u32 value)
{
	if (!ft_u32_oprint(output, value))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
