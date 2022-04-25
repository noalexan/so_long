/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:27:34 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/25 18:57:43 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	settings(t_window *window)
{
	window->settings.max_lives = 5;
	window->settings.window_title = "So Long";
	window->settings.floor = "lib/sprites/wooden.xpm";
	window->settings.wall = "lib/sprites/fence.xpm";
	window->settings.player[0] = "lib/sprites/player/player_north.xpm";
	window->settings.player[1] = "lib/sprites/player/player_east.xpm";
	window->settings.player[2] = "lib/sprites/player/player_south.xpm";
	window->settings.player[3] = "lib/sprites/player/player_west.xpm";
	window->settings.health[0] = "lib/sprites/lives/lost_health.xpm";
	window->settings.health[1] = "lib/sprites/lives/red_health.xpm";
}
