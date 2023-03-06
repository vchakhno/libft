/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:08:48 by vchakhno          #+#    #+#             */
/*   Updated: 2023/03/06 14:33:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>

#define FT_WRITE_MAX_RETRY 3

size_t	ft_safe_write(int fd, void *ptr, size_t size)
{
	size_t	total_write;
	ssize_t	last_write;
	int		retry;

	retry = 0;
	total_write = 0;
	while (total_write < size && retry < FT_WRITE_MAX_RETRY)
	{
		last_write = write(fd, ptr, size - total_write);
		if (last_write == -1)
			return (total_write);
		if (last_write == 0)
			retry++;
		total_write += last_write;
	}
	return (total_write);
}
