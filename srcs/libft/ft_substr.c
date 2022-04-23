/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:19:17 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 12:49:30 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*ft_strndup(char *s, size_t n)
{
	char		*m;
	size_t		i;

	m = malloc(n + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (i < n)
	{
		m[i] = s[i];
		i++;
	}
	m[i] = 0;
	return (m);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (0);
	if (start >= ft_strlen((char *) s) || !s)
		return (malloc(sizeof(char) * 1));
	if (start + len > ft_strlen((char *) s))
		return (ft_strdup((char *) &s[start]));
	return (ft_strndup((char *) &s[start], len));
}
