/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 04:30:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 03:55:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printf.h"

static void	ft_printf_impl(
	t_output *output, t_str_scanner *scanner, va_list args
) {
	while (!ft_str_scanner_has_ended(scanner)
		&& !ft_output_has_ended(output))
	{
		if (ft_str_scanner_match(scanner, '{'))
		{
			ft_try_print_label(output, scanner, args);
		}
		else
		{
			ft_str_scanner_advance(scanner);
			ft_str_scanner_write(scanner, output);
		}
	}
}

void	ft_printf(char *format, ...)
{
	va_list			args;
	t_str_scanner	scanner;

	va_start(args, format);
	ft_str_scanner_init(&scanner, format);
	ft_printf_impl(ft_stdout(), &scanner, args);
	va_end(args);
}

void	ft_println(char *format, ...)
{
	va_list			args;
	t_str_scanner	scanner;

	va_start(args, format);
	ft_str_scanner_init(&scanner, format);
	ft_printf_impl(ft_stdout(), &scanner, args);
	ft_c_str_print("\n");
	va_end(args);
}
