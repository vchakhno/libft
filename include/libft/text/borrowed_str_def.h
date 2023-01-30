/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borrowed_str_def.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:58:42 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:30:00 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BORROWED_STR_DEF_H
# define BORROWED_STR_DEF_H

# include <stddef.h>

typedef struct s_borrowed_str
{
	char	*c_str;
	size_t	len;
}	t_borrowed_str;

#endif