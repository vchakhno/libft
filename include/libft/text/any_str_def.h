/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_str_def.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 10:29:25 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANY_STR_DEF_H
# define ANY_STR_DEF_H
# ifdef ANY_STR_INTERNAL_H
#  include "borrowed_str_def.h"

typedef t_borrowed_str	t_any_str;

# else

typedef void			t_any_str;

# endif
#endif