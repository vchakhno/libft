/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:41:31 by vchakhno          #+#    #+#             */
/*   Updated: 2023/05/18 11:17:48 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdbool.h>
# include <libft/arithmetic/fixed_types.h>
# include <libft/io/ostream/ostream.h>

typedef struct s_borrowed_array
{
	void	*elems;
	t_u32	size;
	t_u32	elem_size;
}	t_borrowed_array;

# ifndef ARRAY_INTERNALS_H

typedef void				t_any_array;

# else

typedef t_borrowed_array	t_any_array;

# endif

/******************************************************************************/
/* BORROWING																  */
/******************************************************************************/

t_borrowed_array	ft_borrowed_array_from_parts(void *elems,
						t_u32 elem_size, t_u32 size);
t_borrowed_array	ft_array_borrow(t_any_array *array);
t_borrowed_array	ft_array_borrow_slice__unchecked(t_any_array *array,
						t_u32 start, t_u32 len);
t_borrowed_array	ft_array_borrow_slice(t_any_array *array,
						t_u32 start, t_u32 len);

/******************************************************************************/
/* ACCESSING																  */
/******************************************************************************/

void				*ft_array_at(t_any_array *array, t_u32 i);

/******************************************************************************/
/* SEARCH																	  */
/******************************************************************************/

// (const void *a, const void *b)
typedef bool				(*t_equality_func)();

bool				ft_array_contains(t_any_array *array,
						void *data, t_equality_func func);
bool				ft_array_find(t_any_array *array,
						void *data, t_equality_func func, t_u32 *index);
bool				ft_array_rfind(t_any_array *array,
						void *data, t_equality_func func, t_u32 *index);
t_u32				ft_array_count(t_any_array *array,
						void *data, t_equality_func func);

/******************************************************************************/
/* ORDERING																	  */
/******************************************************************************/

// (const void *a, const void *b)
// true for a > b
typedef bool				(*t_comparison_func)();

bool				ft_array_max(t_any_array *array,
						t_comparison_func func, void *dest);
bool				ft_array_min(t_any_array *array,
						t_comparison_func func, void *dest);
void				ft_array_sort(t_any_array *array,
						t_comparison_func func);

/******************************************************************************/
/* PRINTING																	  */
/******************************************************************************/

// (const void *elem, t_any_ostream *stream)
typedef bool				(*t_print_func)();

bool				ft_array_print(t_any_array *array,
						t_print_func func, char *sep);
bool				ft_array_println(t_any_array *array,
						t_print_func func, char *sep);
bool				ft_array_oprint(t_any_ostream *stream,
						t_any_array *array, t_print_func func, char *sep);
bool				ft_array_oprintln(t_any_ostream *stream,
						t_any_array *array, t_print_func func, char *sep);

#endif