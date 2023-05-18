/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:57:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 12:25:55 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/data/array/array.h>
#include <libft/data/vector.h>
#include <libft/io/printing.h>
#include <stddef.h>
#include <stdio.h>
#include <libft/io/ostream/ostream.h>

bool	_print_elem(t_u32 *elem, t_any_ostream *stream)
{
	return (ft_u32_oprint(stream, *elem));
}

int	main(void)
{
	t_vector	vec;
	t_u32		count;

	ft_vector_alloc_empty(&vec, sizeof(t_u32));
	if (!ft_vector_push_multiple(&vec, (t_u32 []){1, 2, 8, 3}, 4))
	{
		printf("Push failed\n");
		ft_vector_free(&vec);
		return (0);
	}
	ft_array_println(&vec, _print_elem, NULL);
	if (!ft_vector_insert_multiple(&vec, 2, (t_u32 []){5, 6, 7}, 3))
	{
		printf("Insert failed\n");
		ft_vector_free(&vec);
		return (0);
	}
	ft_array_println(&vec, _print_elem, NULL);
	count = ft_vector_remove_multiple(&vec, 2, NULL, 4);
	printf("Removed %d elements\n", count);
	ft_array_print(&vec, _print_elem, NULL);
	ft_vector_free(&vec);
}
