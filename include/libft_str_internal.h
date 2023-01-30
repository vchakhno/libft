/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2023/01/30 07:44:33 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_INTERNAL_H
# define LIBFT_STR_INTERNAL_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_str
{
	char	*c_str;
	size_t	len;
	size_t	capacity;
}	t_str;

typedef struct s_str_slice
{
	char	*c_str;
	size_t	len;
}	t_str_slice;

// Constructor..?
t_str				ft_str_from_parts__unsafe(char *c_str,
						size_t len, size_t capacity);
t_str_slice			ft_str_slice_from_parts__unsafe(char *c_str,
						size_t len);

// Lifecycle/Memory
t_str_slice			ft_str_borrow_c_str(const char *c_str);
bool				ft_str_dup_c_str(t_str *str, const char *c_str)
					__attribute__((warn_unused_result));
bool				ft_str_reserve_exact(t_str *str, size_t capacity)
					__attribute__((warn_unused_result));
bool				ft_str_reserve_pow2(t_str *str, size_t capacity)
					__attribute__((warn_unused_result));
void				ft_str_free(t_str *str);

// Accessing
typedef struct s_maybe_char {
	bool	exists;
	char	c;
}	t_maybe_char;

t_maybe_char		ft_str_get_char(const t_str str, size_t index, char *out);
t_str				ft_str_borrow_slice(
						const t_str str,
						size_t start, size_t len
						);

// Copying
bool				ft_str_dup(t_str *dest, const t_str src)
					__attribute__((warn_unused_result));
bool				ft_str_dup_slice(
						t_str *dest,
						const t_str src,
						size_t start, size_t len
						)
					__attribute__((warn_unused_result));

// Access by pointers
char				*ft_str_at_char(
						const t_str str,
						size_t index,
						char **out
						);
char				*ft_str_first_char(const t_str str, char **out);
char				*ft_str_last_char(const t_str str, char **out);

// Mutation
bool				ft_str_set_char(t_str *str, char c, size_t index);
bool				ft_str_set_slice(
						t_str *str,
						const void *slice,
						size_t start, size_t len
						)
					__attribute__((warn_unused_result));
bool				ft_str_append(t_str *str, const void *suffix_str)
					__attribute__((warn_unused_result));
bool				ft_str_prepend(t_str *str, const void *prefix_str)
					__attribute__((warn_unused_result));

// Comparison
int					ft_str_compare(const t_str str1, const t_str str2);
bool				ft_str_startswith(const t_str str, const t_str prefix);
bool				ft_str_equal(const t_str str1, const t_str str2);

// Searching
typedef struct s_maybe_char_pos
{
	bool	exists;
	size_t	index;
	char	*ptr;
}	t_maybe_char_pos;

typedef struct s_char_pos_out
{
	bool	reversed;
	size_t	*out_index;
	char	**out_ptr;
}	t_find_char_options;

t_maybe_char_pos	ft_str_find_char(
						const t_str haystack,
						char c,
						t_find_char_options *options
						);

typedef struct s_maybe_str_pos
{
	bool	exists;
	size_t	index;
	t_str	str;
}	t_maybe_str_pos;

typedef struct s_find_str_options
{
	bool	reversed;
	size_t	*out_index;
	t_str	*out_str;
}	t_find_str_options;

t_maybe_str_pos		ft_str_find_str(
						const t_str haystack,
						const t_str needle,
						t_find_str_options *options
						);

// Splitting/joining
typedef struct s_str_array
{
	t_str	*strs;
	size_t	size;
}	t_str_array;

typedef struct s_str_slice_array
{
	t_str_slice	*strs;
	size_t		size;
}	t_str_slice_array;

bool				ft_str_split_alloc(const void *str,
						t_str_array *split)
					__attribute__((warn_unused_result));
bool				ft_str_split_borrow(const void *str,
						t_str_slice_array *split)
					__attribute__((warn_unused_result));
bool				ft_str_join(
						t_str *joined,
						const t_str_array strs,
						const t_str delimiter
						)
					__attribute__((warn_unused_result));
t_str_array			ft_str_array_borrow_c_strs(char **strs, int size);
t_str_array			ft_str_array_borrow_chars(char *chars);
void				ft_str_array_free(t_str_array *array);
void				ft_str_slice_array_free(t_str_slice_array *array);

// Parsing, conversions
typedef struct s_maybe_int
{
	bool	exists;
	int		value;
}	t_maybe_int;

typedef struct s_maybe_float
{
	bool	exists;
	float	value;
}	t_maybe_float;

bool				ft_str_from_int(t_str *str, int n)
					__attribute__((warn_unused_result));
t_maybe_int			ft_int_from_str(const t_str str, int *out);
t_maybe_float		ft_float_from_str(const t_str str, int *out);

// Checking
bool				ft_str_is_alpha(const t_str str);
bool				ft_str_is_alnum(const t_str str);
bool				ft_str_is_digit(const t_str str);
bool				ft_str_is_blank(const t_str str);
bool				ft_str_is_upper(const t_str str);
bool				ft_str_is_lower(const t_str str);

// 
typedef char		(*t_char_functor)(char);
bool				ft_str_map(const t_str str, t_char_functor f);
bool				ft_str_apply(const t_str str, t_char_functor f);

#endif