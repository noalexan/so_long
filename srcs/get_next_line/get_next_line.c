/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:08:33 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/22 16:00:01 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		add_buffer(&save[fd], buffer);
		if (there_is_a_end_of_line(save[fd]) != -1)
			return (get_line(&save[fd]));
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (get_line(&save[fd]));
}
