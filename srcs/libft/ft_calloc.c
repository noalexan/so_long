/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:57:52 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 12:49:30 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*result;

	result = malloc(elementCount * elementSize);
	if (!result)
		return (NULL);
	ft_bzero(result, (elementCount * elementSize));
	return (result);
}
