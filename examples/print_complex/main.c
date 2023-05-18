/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:38:23 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:59:56 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printing/printing_fixed_types.h>
#include <libft/data/str/str.h>

int	main(void)
{
	ft_cf128_println(0.f);
	ft_cf128_println(-0.f);
	ft_cf128_println(1.f);
	ft_cf128_println(0.99f);
	ft_cf128_println(1.01f);
	ft_cf128_println(8.9f);
	ft_cf128_println(0.001f);
	ft_cf128_println(0.0012f);
	ft_cf128_println(0.012f);
	ft_cf128_println(1.f / 0.f);
	ft_cf128_println(0.f / 0.f);
	ft_c_str_println("======");
	ft_cf128_println(0.if);
	ft_cf128_println(0.0f -0.if);
	ft_cf128_println(1.if);
	ft_cf128_println(0.99if);
	ft_cf128_println(1.01if);
	ft_cf128_println(8.9if);
	ft_cf128_println(0.001if);
	ft_cf128_println(0.0012if);
	ft_cf128_println(0.012if);
	ft_cf128_println(1.if / 0.f);
	ft_cf128_println(0.if / 0.f);
	ft_c_str_println("======");
	ft_cf128_println(1.f / 0.f * (1.f + 1.if));
}
