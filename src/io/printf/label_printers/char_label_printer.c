/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_label_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:27:02 by vchakhno          #+#    #+#             */
/*   Updated: 2023/06/03 21:26:57 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printf.h"

void	ft_char_label_printer(t_any_ostream *any_output, va_list args)
{
	ft_ostream_write_byte(any_output, va_arg(args, int));
}
