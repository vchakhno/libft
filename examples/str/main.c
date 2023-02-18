/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:13:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/15 01:11:43 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	t_str	str;

	if (!ft_str_dup_c_str(&str, "Bonjour Velimir"))
	{
		printf("Dup failed\n");
		return (0);
	}
	if (!ft_str_set_slice(&str, ft_str_borrow_c_str("Sabri", NULL), 8, 4))
	{
		printf("Set slice failed\n");
		return (0);
	}
	printf("Str: [%s]\n", str.c_str);
	ft_str_free(&str);
}
