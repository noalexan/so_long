/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:36:18 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 18:02:53 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_percent(va_list param, const char character)
{
	if (character == 's')
		return (ft_putstr(va_arg(param, char *)));
	else if (character == 'c')
		return (ft_putchar(va_arg(param, int)));
	else if (character == 'd' || character == 'i')
		return (ft_putnbr(va_arg(param, int)));
	else if (character == '%')
		return (ft_putchar('%'));
	else if (character == 'x')
		return (ft_puthexa(va_arg(param, unsigned int), 0, 0));
	else if (character == 'X')
		return (ft_puthexa(va_arg(param, unsigned int), 1, 0));
	else if (character == 'p')
		return (ft_puthexa(va_arg(param, unsigned long), 0, 1));
	else if (character == 'u')
		return (ft_putunsignednbr(va_arg(param, unsigned int)));
	else
		return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	param;
	int		i;
	int		size;

	va_start(param, string);
	i = 0;
	size = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			size += ft_percent(param, string[i]);
		}
		else
			size += ft_putchar(string[i]);
		i++;
	}
	return (size);
}

void	err(const char *string, ...)
{
	va_list	param;
	int		i;
	int		size;

	va_start(param, string);
	i = 0;
	size = 0;
	write(1, "Erreur: ", 9);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			size += ft_percent(param, string[i]);
		}
		else
			size += ft_putchar(string[i]);
		i++;
	}
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
