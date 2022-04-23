/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:07:26 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 18:02:41 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
int		ft_putchar(const char character);
int		ft_putnbr(int nb);
int		ft_putunsignednbr(unsigned int nb);
int		ft_putstr(char *str);
int		ft_puthexa(unsigned long nb, int upper, int add);

void	err(const char *string, ...);

#endif
