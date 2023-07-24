/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:07:24 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 03:59:23 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str.h"
#include "libft/io/output.h"
#include "libft/io/printf.h"

bool	ft_str_print(t_any_str *any_str)
{
	return (ft_str_oprint(ft_stdout(), any_str));
}

bool	ft_str_println(t_any_str *any_str)
{
	return (ft_str_oprintln(ft_stdout(), any_str));
}

bool	ft_str_oprint(t_output *output, t_any_str *any_str)
{
	t_borrowed_str *const	str = any_str;

	return (ft_output_write(output, str->c_str, str->len));
}

bool	ft_str_oprintln(t_output *output, t_any_str *any_str)
{
	if (!ft_str_oprint(output, any_str))
		return (false);
	return (ft_output_write(output, "\n", 1));
}
