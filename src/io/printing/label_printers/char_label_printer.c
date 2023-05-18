/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_label_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:27:02 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:57:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing/printf.h"

void	ft_char_label_printer(t_any_ostream *output, va_list args)
{
	ft_ostream_write_byte(output, va_arg(args, int));
}
