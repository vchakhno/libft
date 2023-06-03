/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:16:34 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 20:48:14 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/array.h"
#include "libft/io/ostream/ostream.h"
#include "libft/data/str.h"
#include "libft/io/printf.h"

bool	ft_array_print(
	t_any_array *any_array, t_print_func func, char *sep
) {
	return (ft_array_oprint(ft_stdout(), any_array, func, sep));
}

bool	ft_array_println(
	t_any_array *any_array, t_print_func func, char *sep
) {
	return (ft_array_oprintln(ft_stdout(), any_array, func, sep));
}

bool	ft_array_oprint(
	t_any_ostream *stream, t_any_array *any_array, t_print_func func, char *sep
) {
	t_borrowed_array *const	array = any_array;
	t_u32					i;

	if (!sep)
		sep = ", ";
	ft_ostream_write_byte(stream, '[');
	i = 0;
	while (i < array->size)
	{
		if (!func(ft_array_at(array, i), stream)
			|| (i != array->size - 1 && !ft_c_str_oprint(stream, sep)))
			return (false);
		i++;
	}
	ft_ostream_write_byte(stream, ']');
	return (true);
}

bool	ft_array_oprintln(
	t_any_ostream *stream, t_any_array *any_array, t_print_func func, char *sep
) {
	if (!ft_array_oprint(stream, any_array, func, sep))
		return (false);
	return (ft_ostream_write_byte(stream, '\n'));
}
