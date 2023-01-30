/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_c_str.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 07:37:07 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 07:37:43 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_C_STR_H
# define LIBFT_C_STR_H

# include <stddef.h>

// C str
size_t	ft_c_str_len(const char *c_str);
void	ft_c_str_ncopy(char *dest, const char *src, size_t len);
bool	ft_c_str_ndup__unchecked(char **dest, const char *src,
			size_t len, size_t capacity);

#endif