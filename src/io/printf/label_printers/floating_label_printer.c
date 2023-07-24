/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating_label_printer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:27:02 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/24 03:52:28 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printf.h"
#include "libft/io/printing.h"
#include "libft/arithmetic/fixed_types.h"

void	ft_f32_label_printer(t_output *output, va_list args)
{
	ft_f32_oprint(output, va_arg(args, t_f64));
}

void	ft_f64_label_printer(t_output *output, va_list args)
{
	ft_f64_oprint(output, va_arg(args, t_f64));
}

void	ft_f80_label_printer(t_output *output, va_list args)
{
	ft_f80_oprint(output, va_arg(args, t_f80));
}

void	ft_f128_label_printer(t_output *output, va_list args)
{
	ft_f128_oprint(output, va_arg(args, t_f128));
}
