/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_label_printer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:27:02 by vchakhno          #+#    #+#             */
/*   Updated: 2023/07/23 04:34:53 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printf.h"
#include "libft/io/printing.h"
#include "libft/arithmetic/fixed_types.h"

void	ft_u8_label_printer(t_any_ostream *any_output, va_list args)
{
	ft_u8_oprint(any_output, va_arg(args, t_u32));
}

void	ft_u16_label_printer(t_any_ostream *any_output, va_list args)
{
	ft_u16_oprint(any_output, va_arg(args, t_u32));
}

void	ft_u32_label_printer(t_any_ostream *any_output, va_list args)
{
	ft_u32_oprint(any_output, va_arg(args, t_u32));
}

void	ft_u64_label_printer(t_any_ostream *any_output, va_list args)
{
	ft_u64_oprint(any_output, va_arg(args, t_u64));
}
