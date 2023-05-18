/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_str_formatting.c                           :+:      :+:    :+:   */
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

void	ft_test_str_expand_tabs(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "\tint\t\tnumber;"))
	{
		printf("Allocation error\n");
		return ;
	}
	printf("%.*s\n", (int) str.len, str.c_str);
	ft_str_expand_tabs(&str, 4);
	printf("%.*s\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

void	ft_test_str_formatting(void)
{
	ft_test_str_expand_tabs();
}
