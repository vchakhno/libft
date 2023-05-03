/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_str_adding.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:13:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/03 17:11:14 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str.h"
#include <stdio.h>

void	ft_test_str_insert(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "Bonjour, comment ça va ?"))
		return ;
	ft_str_insert_c_str(&str, 7, " Vélimir");
	printf("%.*s\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

void	ft_test_str_adding(void)
{
	ft_test_str_insert();
}
