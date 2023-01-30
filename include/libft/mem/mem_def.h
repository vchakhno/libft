/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 11:07:38 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_DEF_H
# define MEM_DEF_H
# ifdef MEM_INTERNAL_H

typedef unsigned char	t_byte;
typedef t_byte			t_mem;

# else

typedef unsigned char	t_byte;
typedef void			t_mem;

# endif
#endif