/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:07:24 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 04:43:35 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str.h"
#include "libft/io/output.h"
#include "libft/io/printf.h"

bool	ft_str_print(t_str str)
{
	return (ft_str_oprint(ft_stdout(), str));
}

bool	ft_str_println(t_str str)
{
	return (ft_str_oprintln(ft_stdout(), str));
}

bool	ft_str_oprint(t_output *output, t_str str)
{
	return (ft_output_write(output, str.c_str, str.len));
}

bool	ft_str_oprintln(t_output *output, t_str str)
{
	if (!ft_str_oprint(output, str))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
