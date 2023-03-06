/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_scanner2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:15:41 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 20:20:40 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printf.h"
#include "libft/str/str.h"
#include "libft/mem/mem.h"

void	ft_str_scanner_discard(t_str_scanner *scanner)
{
	scanner->write_pos = scanner->read_pos;
}

void	ft_str_scanner_write(t_str_scanner *scanner, t_any_ostream *output)
{
	ft_ostream_write(output,
		scanner->str.c_str + scanner->write_pos,
		scanner->read_pos - scanner->write_pos);
	scanner->write_pos = scanner->read_pos;
}

bool	ft_str_scanner_match_c_str(t_str_scanner *scanner, char *c_str)
{
	size_t	len;

	len = ft_c_str_len(c_str);
	if (len > scanner->str.len - scanner->read_pos)
		return (false);
	if (ft_mem_equal(scanner->str.c_str + scanner->read_pos,
			c_str, len))
	{
		scanner->read_pos += len;
		return (true);
	}
	return (false);
}
