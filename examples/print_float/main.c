/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:38:23 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/15 01:41:19 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/fixed_types.h>
#include <libft/ostream/ostream.h>
#include <libft/float_math.h>
#include <stdio.h>

#include <stdint.h>

int	main(void)
{
	t_f128	v;

	// v = 0.0001001q;
	// v = 1.q/0.q;
	v = 0.l/(1.il - 1.il);
	ft_f80_println(v);
}
