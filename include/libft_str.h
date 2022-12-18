/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:58:20 by vchakhno          #+#    #+#             */
/*   Updated: 2022/12/18 11:19:24 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
# define LIBFT_STR_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_str
{
	char	*c_str;
	size_t	len;
	size_t	capacity;
}	t_str;

// C str
size_t				ft_c_str_len(const char *c_str);
void				ft_c_str_ncopy(char *dest, const char *src, size_t len);

// Lifecycle/Memory
bool				ft_str_alloc(t_str *str, const char *c_str, size_t len)
					__attribute__((warn_unused_result));
t_str				ft_str_borrow_c_str(const char *c_str, t_str *out);
bool				ft_str_dup_c_str(t_str *str, const char *c_str)
					__attribute__((warn_unused_result));
bool				ft_str_from_int(t_str *str, int n)
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
						size_t start, size_t len,
						t_str *out
						);

// Copying
bool				ft_str_dup(const t_str str, t_str *dupped)
					__attribute__((warn_unused_result));
bool				ft_str_dup_slice(
						const t_str str,
						t_str *dupped,
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
						t_str slice,
						size_t start, size_t len
						)
					__attribute__((warn_unused_result));
bool				ft_str_append(t_str *str, const t_str suffix)
					__attribute__((warn_unused_result));
bool				ft_str_prepend(t_str *str, const t_str prefix)
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
	size_t	*out_index;
	char	**out_ptr;
}	t_char_pos_out;

t_maybe_char_pos	ft_str_find_char(
						const t_str haystack,
						char c,
						bool reversed,
						t_char_pos_out out
						);

typedef struct s_maybe_str_pos
{
	bool	exists;
	size_t	index;
	t_str	str;
}	t_maybe_str_pos;

typedef struct s_str_pos_out
{
	size_t	*out_index;
	t_str	*out_ptr;
}	t_str_pos_out;

t_maybe_str_pos		ft_str_find_str(
						const t_str haystack,
						const t_str needle,
						bool reversed,
						t_str_pos_out out
						);

// Splitting/joining
typedef struct s_str_array
{
	t_str	*strs;
	int		size;
}	t_str_array;

bool				ft_str_split(t_str *str, t_str_array *split)
					__attribute__((warn_unused_result));
bool				ft_str_join(
						t_str *joined,
						const t_str_array strs,
						const t_str delimiter
						)
					__attribute__((warn_unused_result));
t_str_array			ft_str_array_borrow(
						char **strs, int size,
						t_str_array *out
						);
void				ft_str_array_free(t_str_array *vec);

// Parsing
typedef struct s_maybe_int
{
	bool	exists;
	int		value;
}	t_maybe_int;

t_maybe_int			ft_int_from_str(const t_str str, int *out);

#endif