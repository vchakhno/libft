/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/21 20:14:23 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEM_H
# define LIBFT_MEM_H

# include <stddef.h>
# include <stdbool.h>

typedef unsigned char	t_byte;

void	*ft_mem_calloc(size_t count, size_t size);
int		ft_mem_compare(const void *ptr1, const void *ptr2, size_t n);
bool	ft_mem_equal(const void *ptr1, const void *ptr2, size_t n);
void	ft_mem_copy(void *dest, const void *src, size_t size);
void	*ft_mem_find(const void *ptr, size_t size, t_byte b);
bool	ft_mem_index(const void *ptr, size_t size, t_byte b, size_t *index);
void	ft_mem_move(void *dest, const void *src, size_t size);
void	ft_mem_set(void *ptr, size_t size, t_byte b);
void	ft_mem_zero(void *ptr, size_t size);
bool	ft_mem_malloc(void *dest, size_t size)
		__attribute__((warn_unused_result));

#endif