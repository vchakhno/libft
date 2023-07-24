/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_label_printer.c                           :+:      :+:    :+:   */
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

void	ft_u8_label_printer(t_output *output, va_list args)
{
	ft_u8_oprint(output, va_arg(args, t_u32));
}

void	ft_u16_label_printer(t_output *output, va_list args)
{
	ft_u16_oprint(output, va_arg(args, t_u32));
}

void	ft_u32_label_printer(t_output *output, va_list args)
{
	ft_u32_oprint(output, va_arg(args, t_u32));
}

void	ft_u64_label_printer(t_output *output, va_list args)
{
	ft_u64_oprint(output, va_arg(args, t_u64));
}
