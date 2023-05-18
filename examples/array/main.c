/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:57:43 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 12:33:16 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/data/array/array.h>
#include <libft/io/printing.h>
#include <stddef.h>
#include <stdio.h>
#include <libft/io/ostream/ostream.h>

bool	_print_elem(t_f64 *elem, t_any_ostream *stream)
{
	return (ft_f64_oprint(stream, *elem));
}

bool	_compare_elems(t_f64 *a, t_f64 *b)
{
	return (*a > *b);
}

int	main(void)
{
	t_borrowed_array	array;
	t_f64				max;

	array = ft_borrowed_array_from_parts(
			(t_f64 [5]){1.2, 5.8, 3, 4.4, 2.1}, sizeof(t_f64), 5);
	ft_array_println(&array, _print_elem, NULL);
	if (ft_array_max(&array, _compare_elems, &max))
	{
		printf("Maximum: %f\n", max);
	}
	// ft_array_println(&array, _print_elem, NULL);
}
