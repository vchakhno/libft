/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_str_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:13:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/02/28 04:32:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str/str.h"
#include <stdio.h>
#include <stddef.h>

void	ft_test_str_find_char(void)
{
	t_str_slice	str;
	char		c;
	size_t		pos;

	str = ft_c_str_borrow("Velimir");
	c = 'm';
	printf("Searching char '%c' in string \"%.*s\"\n",
		c, (int) str.len, str.c_str);
	if (!ft_str_find_char(&str, c, &pos))
	{
		printf("The character was not found.\n\n");
		return ;
	}
	printf("Found in position: %d\n\n", (int) pos);
}

void	ft_test_str_search(void)
{
	ft_test_str_find_char();
}
