/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:07:24 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:48:39 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str_internals.h"
#include "libft/io/printing/ostream/ostream.h"
#include "libft/io/printing/printf.h"

bool	ft_str_print(t_any_str *str)
{
	return (ft_str_oprint(ft_stdout(), str));
}

bool	ft_str_println(t_any_str *str)
{
	return (ft_str_oprintln(ft_stdout(), str));
}

bool	ft_str_oprint(t_any_str_ostream *stream, t_any_str *str)
{
	return (ft_ostream_write(stream, str->c_str, str->len));
}

bool	ft_str_oprintln(t_any_str_ostream *stream, t_any_str *str)
{
	if (!ft_str_oprint(stream, str))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
