/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:57:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 11:27:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/data/array/array.h>
#include <libft/io/printing.h>
#include <stddef.h>
#include <libft/io/ostream/ostream.h>

bool	_print_elem(t_u32 *elem, t_any_ostream *stream)
{
	return (ft_u32_oprint(stream, *elem));
}

int	main(void)
{
	t_borrowed_array	array;

	array = ft_borrowed_array_from_parts(
			(t_u32 [5]){1, 5, 3, 4, 2}, sizeof(int), 5);
	ft_array_println(&array, _print_elem, NULL);
	ft_array_sort(&array, NULL);
	ft_array_println(&array, _print_elem, NULL);
}
