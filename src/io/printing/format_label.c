/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 04:30:22 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:42:51 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/printing/printf.h"

typedef void	(*t_label_printer)(t_any_ostream *output, va_list args);
typedef struct s_label_info
{
	char			*name;
	t_label_printer	printer;
}	t_label_info;

bool	ft_match_label_types(t_str_scanner *scanner, t_label_printer *printer)
{
	static t_label_info	map[] = {
	{"str", ft_str_label_printer},
	{"c_str", ft_c_str_label_printer},
	{"char", ft_char_label_printer},
	};
	int					i;

	i = 0;
	while (i < (int)(sizeof(map) / sizeof(*map)))
	{
		if (ft_str_scanner_match_c_str(scanner, map[i].name))
		{
			*printer = map[i].printer;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_parse_label(t_str_scanner *scanner, t_label_printer *printer)
{
	if (!ft_match_label_types(scanner, printer))
		return (false);
	if (!ft_str_scanner_match(scanner, '}'))
		return (false);
	return (true);
}

void	ft_try_print_label(t_any_ostream *output, t_str_scanner *scanner,
	va_list args)
{
	t_label_printer	printer;

	if (ft_parse_label(scanner, &printer))
	{
		ft_str_scanner_discard(scanner);
		printer(output, args);
	}
	else
	{
		ft_str_scanner_write(scanner, output);
	}
}
