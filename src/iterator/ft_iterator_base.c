/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:41:46 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/20 12:49:32 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/iterator/iterator_types.h"

void	ft_iterator_base_init(t_iterator_base *iterator, t_iterator_next next)
{
	iterator->next = next;
}
