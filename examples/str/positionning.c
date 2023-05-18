/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_str_positionning.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:13:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:50:21 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include "libft/data/iterator/iterator.h"
#include <stdio.h>

void	ft_test_str_center(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "Center this"))
	{
		printf("Allocation failed\n");
		return ;
	}
	ft_str_center(&str, 20, '*');
	printf("[%.*s]\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

void	ft_test_str_ljust(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "Ljust this"))
	{
		printf("Allocation failed\n");
		return ;
	}
	ft_str_ljust(&str, 20, '*');
	printf("[%.*s]\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

void	ft_test_str_rjust(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "Rjust this"))
	{
		printf("Allocation failed\n");
		return ;
	}
	ft_str_rjust(&str, 20, '*');
	printf("[%.*s]\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

void	ft_test_str_positionning(void)
{
	ft_test_str_center();
	ft_test_str_ljust();
	ft_test_str_rjust();
}
