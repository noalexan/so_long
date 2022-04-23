/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:16:41 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 12:49:30 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*strmapi;
	unsigned int	i;

	if (!s)
		return (NULL);
	strmapi = ft_strdup(s);
	if (!strmapi)
		return (0);
	i = -1;
	while (strmapi[++i])
		strmapi[i] = f(i, strmapi[i]);
	return (strmapi);
}
