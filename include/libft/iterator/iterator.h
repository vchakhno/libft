/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:42:59 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/20 12:48:40 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
# define ITERATOR_H
# ifndef ITERATOR_INTERNAL_TYPES_H
#  include "iterator_types.h"
# endif

# include <stdbool.h>

void	ft_iterator_base_init(t_iterator_base *iterator, t_iterator_next next);
bool	ft_iterator_next(t_any_iterator *iterator, void *dest);

#endif