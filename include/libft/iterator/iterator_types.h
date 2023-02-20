/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:38:54 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/20 12:45:42 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TYPES_H
# define ITERATOR_TYPES_H

# include <stdbool.h>

//	(t_any_iter	*iter, void *dest)
typedef bool	(*t_iterator_next)();
typedef struct s_iterator_base
{
	t_iterator_next	next;	
}	t_iterator_base;

typedef void	t_any_iterator;

#endif