/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:41:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:22:26 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/iterator/iterator_internals.h"

bool	ft_iterator_next(t_any_iterator *iterator, void *dest)
{
	return (iterator->next(iterator, dest));
}
