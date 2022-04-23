/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:27 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 12:49:30 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	size_t			i;
	long			sz;
	unsigned char	*d;
	unsigned char	*s;

	i = -1;
	sz = (long) size + 1;
	d = (unsigned char *) destination;
	s = (unsigned char *) source;
	if (!destination || !source)
		return (NULL);
	if (s < d)
		while (--sz > 0)
			d[sz - 1] = s[sz - 1];
	else if (s > d)
		while (++i < size)
			d[i] = s[i];
	return (destination);
}
