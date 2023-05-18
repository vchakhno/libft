/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:42:55 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 09:14:13 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/io/ostream/ostream.h"
# include "libft/data/str/str.h"
# include <stddef.h>
# include <stdbool.h>
# include <stdarg.h>

void				ft_printf(char *format, ...);
void				ft_println(char *format, ...);
size_t				ft_ostream_writef(t_any_ostream *stream, char *format, ...);

t_buffered_ostream	*ft_stdout(void);
t_fd_ostream		*ft_stderr(void);

typedef struct s_str_scanner
{
	t_borrowed_str	str;
	size_t			read_pos;
	size_t			write_pos;
}	t_str_scanner;

void				ft_str_scanner_init(t_str_scanner *scanner, char *str);
bool				ft_str_scanner_has_ended(t_str_scanner *scanner);
void				ft_str_scanner_advance(t_str_scanner *scanner);
void				ft_str_scanner_discard(t_str_scanner *scanner);
bool				ft_str_scanner_match(t_str_scanner *scanner, char c);
bool				ft_str_scanner_match_c_str(t_str_scanner *scanner,
						char *c_str);
void				ft_str_scanner_write(t_str_scanner *scanner,
						t_any_ostream *output);

void				ft_try_print_label(t_any_ostream *output,
						t_str_scanner *scanner, va_list args);

void				ft_str_label_printer(t_any_ostream *output, va_list args);
void				ft_c_str_label_printer(t_any_ostream *output, va_list args);
void				ft_char_label_printer(t_any_ostream *output, va_list args);

#endif