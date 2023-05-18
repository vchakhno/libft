/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:38:23 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 08:05:53 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printing/printing_fixed_types.h>

int	main(void)
{
	ft_f128_println(0.f);
	ft_f128_println(1.f);
	ft_f128_println(0.99f);
	ft_f128_println(1.01f);
	ft_f128_println(8.9f);
	ft_f128_println(0.001f);
	ft_f128_println(0.0012f);
	ft_f128_println(0.012f);
	ft_f128_println(1.f / 0.f);
	ft_f128_println(0.f / 0.f);
}
