/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_str_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:10:42 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 03:59:21 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/output.h"
#include "libft/data/str.h"
#include "libft/io/printf.h"

bool	ft_c_str_print(char *c_str)
{
	return (ft_c_str_oprint(ft_stdout(), c_str));
}

bool	ft_c_str_println(char *c_str)
{
	return (ft_c_str_oprintln(ft_stdout(), c_str));
}

bool	ft_c_str_oprint(t_output *output, char *c_str)
{
	return (ft_output_write(output, c_str, ft_c_str_len(c_str)));
}

bool	ft_c_str_oprintln(t_output *output, char *c_str)
{
	if (!ft_c_str_oprint(output, c_str))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
