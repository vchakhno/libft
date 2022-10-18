/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 03:20:19 by vchakhno          #+#    #+#             */
/*   Updated: 2022/10/18 03:30:28 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*mapped_first;
	t_list	*mapped_last;
	t_list	*new_node;

	current = lst;
	while (current)
	{
		new_node = ft_lstnew(f(current->content));
		if (!new_node)
		{
			ft_lstclear(mapped_first, del);
			return (NULL);
		}
		if (!mapped_first)
			mapped_first = new_node;
		else
			mapped_last->next = new_node;
		mapped_last = new_node;
		current = current->next;
	}
	return (mapped_first);
}
