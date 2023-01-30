/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 08:23:25 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_H
# define CHAR_H

# include <stdbool.h>

bool	ft_char_is_alnum(char c);
bool	ft_char_is_alpha(char c);
bool	ft_char_is_ascii(char c);
bool	ft_char_is_digit(char c);
bool	ft_char_is_lower(char c);
bool	ft_char_is_print(char c);
bool	ft_char_is_upper(char c);
bool	ft_char_is_blank(char c);
char	ft_char_to_lower(char c);
char	ft_char_to_upper(char c);

#endif