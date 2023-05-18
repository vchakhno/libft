/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_label_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:27:02 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 09:16:14 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printf.h"
#include "libft/data/str/str.h"

void	ft_str_label_printer(t_any_ostream *output, va_list args)
{
	ft_str_oprint(output, va_arg(args, t_any_str *));
}
