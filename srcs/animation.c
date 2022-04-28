/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:20:42 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 13:03:47 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	animate_collectibles(t_window *window, int *c)
{
	(void) window;
	if (*c / window->settings.frame_speed == 1
		&& *c % window->settings.frame_speed == 0)
		;
	else if (*c / (window->settings.frame_speed * 2) == 1
		&& *c % (window->settings.frame_speed * 2) == 0)
		;
	else if (*c / (window->settings.frame_speed * 3) == 1
		&& *c % (window->settings.frame_speed * 3) == 0)
		;
	else if (*c / (window->settings.frame_speed * 4) == 1
		&& *c % (window->settings.frame_speed * 4) == 0)
	{
		*c = 0;
	}
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
