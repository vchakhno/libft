/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocated_str.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:10:27 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 09:11:45 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATED_STR_H
# define ALLOCATED_STR_H

# include <stddef.h>

typedef struct s_allocated_str
{
	char	*c_str;
	size_t	len;
	size_t	capacity;
}	t_allocated_str;

#endif