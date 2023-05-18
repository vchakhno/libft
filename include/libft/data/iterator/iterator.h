/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:42:59 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 13:21:23 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
# define ITERATOR_H

# include <stdbool.h>

//	(t_any_iter	*iter, void *dest)
typedef bool			(*t_iterator_next)();

typedef struct s_iterator_base
{
	t_iterator_next	next;	
}	t_iterator_base;

# ifndef ITERATOR_INTERNALS_H

typedef void			t_any_iterator;

# else

typedef t_iterator_base	t_any_iterator;

# endif

void	ft_iterator_base_init(t_iterator_base *iterator, t_iterator_next next);
bool	ft_iterator_next(t_any_iterator *iterator, void *dest);

#endif