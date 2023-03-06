/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:08:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 14:33:53 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>

#define FT_READ_MAX_RETRY 3

size_t	ft_safe_read(int fd, void *ptr, size_t size)
{
	size_t	total_read;
	ssize_t	last_read;
	int		retry;

	retry = 0;
	total_read = 0;
	while (total_read < size && retry < FT_READ_MAX_RETRY)
	{
		last_read = read(fd, ptr, size - total_read);
		if (last_read == -1)
			return (total_read);
		if (last_read == 0)
			retry++;
		total_read += last_read;
	}
	return (total_read);
}
