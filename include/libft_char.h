/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_char.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/08 06:51:06 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CHAR_H
# define LIBFT_CHAR_H

# include <stdbool.h>

bool	ft_char_isalnum(int c);
bool	ft_char_isalpha(int c);
bool	ft_char_isascii(int c);
bool	ft_char_isdigit(int c);
bool	ft_char_islower(int c);
bool	ft_char_isprint(int c);
bool	ft_char_isupper(int c);
bool	ft_char_iswhitespace(int c);
bool	ft_char_tolower(int c);
bool	ft_char_toupper(int c);

#endif