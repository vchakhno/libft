/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:41:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/20 12:57:23 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/iterator/iterator_internal_types.h"

bool	ft_iterator_next(t_any_iterator *iterator, void *dest)
{
	return (iterator->next(iterator, dest));
}
