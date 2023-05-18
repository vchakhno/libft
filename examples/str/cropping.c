/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_str_cropping.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:13:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 07:50:04 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/data/str/str.h"
#include <stdio.h>

void	ft_test_str_remove_slice(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "Bonjour Vélimir, comment ça va ?"))
		return ;
	ft_str_remove_slice(&str, 7, 9);
	printf("%.*s\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

void	ft_test_str_cropping(void)
{
	ft_test_str_remove_slice();
}
