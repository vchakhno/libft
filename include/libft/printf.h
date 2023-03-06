/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:42:55 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 15:51:26 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/ostream/ostream.h"
# include <stddef.h>
# include <stdbool.h>

void				ft_printf(char *format, ...);
void				ft_println(char *format, ...);
size_t				ft_ostream_writef(t_any_ostream *stream, char *format, ...);

t_buffered_ostream	*ft_stdout(void);

typedef struct s_str_scanner
{
	char	*str;
	int		pos;
}	t_str_scanner;

void				ft_str_scanner_init(t_str_scanner *scanner, char *str);
char				ft_str_scanner_peek(t_str_scanner *scanner);
void				ft_str_scanner_advance(t_str_scanner *scanner);
void				ft_str_scanner_discard(t_str_scanner *scanner);
bool				ft_str_scanner_match(t_str_scanner *scanner, char c);
bool				ft_str_scanner_write(t_str_scanner *scanner,
						t_any_ostream *output);

#endif