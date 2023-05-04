/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_str_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:10:42 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/04 12:23:18 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ostream/ostream.h"
#include "libft/str/str.h"
#include "libft/printf.h"

bool	ft_c_str_print(char *c_str)
{
	return (ft_c_str_oprint(c_str, ft_stdout()));
}

bool	ft_c_str_println(char *c_str)
{
	return (ft_c_str_oprintln(c_str, ft_stdout()));
}

bool	ft_c_str_oprint(char *c_str, t_any_str_ostream *stream)
{
	return (ft_ostream_write(stream, c_str, ft_c_str_len(c_str)));
}

bool	ft_c_str_oprintln(char *c_str, t_any_str_ostream *stream)
{
	if (!ft_c_str_oprint(c_str, stream))
		return (false);
	return (ft_ostream_write(stream, "\n", 1));
}
