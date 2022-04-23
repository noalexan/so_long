/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:19:48 by noahalexand       #+#    #+#             */
/*   Updated: 2022/04/23 12:49:54 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_putchar(const char character)
{
	write(1, &character, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		return (ft_putstr("(null)"));
	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		return (ft_putnbr(-21474) + ft_putnbr(83648));
	if (nb < 0)
		return (ft_putchar('-') + ft_putnbr(nb * -1));
	else if (nb >= 10)
		return (ft_putnbr(nb / 10) + ft_putnbr(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}

int	ft_putunsignednbr(unsigned int nb)
{
	if (nb < 0)
		return (ft_putchar('-') + ft_putnbr(nb * -1));
	else if (nb >= 10)
		return (ft_putnbr(nb / 10) + ft_putnbr(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}

int	ft_puthexa(unsigned long nb, int upper, int add)
{
	char	*dic;

	if (add)
		return (ft_putstr("0x") + ft_puthexa(nb, 0, 0));
	dic = "0123456789abcdef";
	if (upper)
		dic = "0123456789ABCDEF";
	if (nb < 16)
		return (ft_putchar(dic[nb]));
	else
		return (ft_puthexa(nb / 16, upper, 0) + ft_puthexa(nb % 16, upper, 0));
}
