/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:20:42 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 12:42:26 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	animate_collectibles(t_window *window, int *c)
{
	(void) window;
	if (*c / window->settings.frame_speed == 1
		&& *c % window->settings.frame_speed == 0)
		ft_printf("%d\n", *c);
	else if (*c / (window->settings.frame_speed * 2) == 1
		&& *c % (window->settings.frame_speed * 2) == 0)
		ft_printf("%d\n", *c);
	else if (*c / (window->settings.frame_speed * 3) == 1
		&& *c % (window->settings.frame_speed * 3) == 0)
		ft_printf("%d\n", *c);
	else if (*c / (window->settings.frame_speed * 4) == 1
		&& *c % (window->settings.frame_speed * 4) == 0)
	{
		ft_printf("%d\n", *c);
		*c = 0;
	}
	usleep(100000);
}

int	animate(t_window *window)
{
	static int	collectibles = 0;
	static int	ennemies = 0;

	animate_collectibles(window, &collectibles);
	collectibles++;
	ennemies++;
	return (0);
}
