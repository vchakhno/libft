/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borrowed_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:34:34 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/18 21:36:35 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BORROWED_STR_H
# define BORROWED_STR_H

# include "any_str_def.h"
# include "borrowed_str_def.h"
# include <stddef.h>

t_borrowed_str	ft_borrowed_str_from_parts(char *c_str, size_t len);
t_borrowed_str	ft_c_str_borrow(char *c_str);
t_borrowed_str	ft_c_str_borrow_slice__unchecked(char *c_str,
					size_t start, size_t len);
t_borrowed_str	ft_str_borrow(t_any_str *str);
t_borrowed_str	ft_str_borrow_slice__unchecked(t_any_str *str,
					size_t start, size_t len);
t_borrowed_str	ft_str_borrow_slice(t_any_str *str,
					size_t start, size_t len);

#endif