/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 08:28:43 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "libft/text/char.h"
# include "libft/text/str.h"
# include "libft/mem.h"

# include <stddef.h>

// ===== Second part =====

// putfd
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);

// stralloc
char	*ft_itoa(int n);
char	**ft_split(char const *str, char delim);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *str, char const *set);
char	*ft_substr(char const *str, unsigned int start, size_t len);

#endif