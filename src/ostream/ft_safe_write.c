/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:08:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 16:04:27 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

#define FT_WRITE_MAX_RETRY 3

size_t	ft_safe_write(int fd, void *ptr, size_t size)
{
	size_t	total_written;
	ssize_t	last_written;
	int		retry;

	retry = 0;
	total_written = 0;
	while (total_written < size && retry < FT_WRITE_MAX_RETRY)
	{
		last_written = write(fd, ptr, size - total_written);
		if (last_written == -1)
			return (total_written);
		if (last_written == 0)
			retry++;
		total_written += last_written;
	}
	return (total_written);
}
