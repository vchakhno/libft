/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ostream_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:56:54 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 15:20:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSTREAM_TYPES_H
# define OSTREAM_TYPES_H

# include <stddef.h>
# include <stdbool.h>

typedef size_t	(*t_ostream_write)();
typedef struct s_ostream_base
{
	t_ostream_write	write;
	bool			ended;
}	t_ostream_base;

typedef void	t_any_ostream;
typedef void	t_any_str_ostream;

typedef struct s_fd_ostream
{
	t_ostream_base	base;
	int				fd;
}	t_fd_ostream;

typedef struct s_fixed_str_ostream
{
	t_ostream_base	base;
	char			*dest;
	size_t			pos;
	size_t			size;
}	t_fixed_str_ostream;

typedef struct s_array_ostream
{
	t_ostream_base	base;
	void			*array;
	size_t			elem_size;
	size_t			capacity;
	size_t			pos;
}	t_array_ostream;

typedef struct s_buffered_ostream
{
	t_ostream_base	base;
	void			*buffer;
	size_t			buffer_size;
	size_t			pos;
	t_any_ostream	*destination;
}	t_buffered_ostream;

#endif