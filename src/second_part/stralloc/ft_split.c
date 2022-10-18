/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:17:53 by velimir           #+#    #+#             */
/*   Updated: 2022/10/17 17:50:18 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_count_words(const char *str, char delim)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != delim && (i == 0 || str[i - 1] == delim))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_dup_word(char **dest, const char *src, char delim)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != delim)
		i++;
	*dest = malloc(sizeof(char) * (i + 1));
	if (!*dest)
		return (0);
	i = 0;
	while (src[i] && src[i] != delim)
	{
		(*dest)[i] = src[i];
		i++;
	}
	(*dest)[i] = '\0';
	return (i);
}

static size_t	ft_skip_delim(const char *src, char delim)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] == delim)
		i++;
	return (i);
}

char	**ft_split(char const *str, char delim)
{
	char	**words;
	size_t	word_count;
	size_t	str_i;
	size_t	i;

	word_count = ft_count_words(str, delim);
	words = malloc(sizeof(char *) * (word_count + 1));
	str_i = ft_skip_delim(str, delim);
	i = 0;
	while (i < word_count)
	{
		str_i += ft_dup_word(words + i, str + str_i, delim);
		if (!words[i])
			return (words);
		str_i += ft_skip_delim(str + str_i, delim);
		i++;
	}
	words[i] = NULL;
	return (words);
}
