/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_str_stripping.c                            :+:      :+:    :+:   */
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

void	ft_test_str_strip(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "*__*Strip this*__*"))
	{
		printf("Allocation failed\n");
		return ;
	}
	ft_str_strip(&str, "*_");
	printf("[%.*s]\n", (int) str.len, str.c_str);
	ft_str_free(&str);
	if (!ft_str_dup_c_str(&str, "*__*__*__*"))
	{
		printf("Allocation failed\n");
		return ;
	}
	ft_str_strip(&str, "*_");
	printf("[%.*s]\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

void	ft_test_str_lstrip(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "*__*__*__*Lstrip this"))
	{
		printf("Allocation failed\n");
		return ;
	}
	ft_str_lstrip(&str, "*_");
	printf("[%.*s]\n", (int) str.len, str.c_str);
	ft_str_free(&str);
	if (!ft_str_dup_c_str(&str, "*__*__*__*"))
	{
		printf("Allocation failed\n");
		return ;
	}
	ft_str_lstrip(&str, "*_");
	printf("[%.*s]\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

void	ft_test_str_rstrip(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "Rstrip this*__*__*__*"))
	{
		printf("Allocation failed\n");
		return ;
	}
	ft_str_rstrip(&str, "*_");
	printf("[%.*s]\n", (int) str.len, str.c_str);
	ft_str_free(&str);
	if (!ft_str_dup_c_str(&str, "*__*__*__*"))
	{
		printf("Allocation failed\n");
		return ;
	}
	ft_str_rstrip(&str, "*_");
	printf("[%.*s]\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

void	ft_test_str_remove_prefix(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "PrefixBlablaSuffix"))
	{
		printf("Allocation failed\n");
		return ;
	}
	ft_str_remove_c_str_prefix(&str, "Prefix");
	printf("[%.*s]\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

void	ft_test_str_remove_suffix(void)
{
	t_allocated_str	str;

	if (!ft_str_dup_c_str(&str, "PrefixBlablaSuffix"))
	{
		printf("Allocation failed\n");
		return ;
	}
	ft_str_remove_c_str_suffix(&str, "Suffix");
	printf("[%.*s]\n", (int) str.len, str.c_str);
	ft_str_free(&str);
}

void	ft_test_str_stripping(void)
{
	ft_test_str_strip();
	ft_test_str_lstrip();
	ft_test_str_rstrip();
	ft_test_str_remove_prefix();
	ft_test_str_remove_suffix();
}
