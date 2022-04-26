/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:27:34 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/26 14:49:13 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	settings(t_window *window)
{
	window->settings.max_lives = 3;
	window->settings.live_regain = 1;
	window->settings.speed = 16;
	window->settings.level_title_color = RED;
	window->settings.gameover_title_color = RED;
	window->settings.nogui = 0;
	window->settings.window_title = "So Long";
	window->settings.dir_path
		= "/Users/noalexan/Desktop/42Projects/42Cursus/so_long/";
	window->settings.floor = ft_strjoin(window->settings.dir_path,
			"lib/sprites/wooden.xpm");
	window->settings.wall = ft_strjoin(window->settings.dir_path,
			"lib/sprites/fence.xpm");
	window->settings.player[0] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/player/set 2/player_north.xpm");
	window->settings.player[1] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/player/set 2/player_east.xpm");
	window->settings.player[2] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/player/set 2/player_south.xpm");
	window->settings.player[3] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/player/set 2/player_west.xpm");
	window->settings.health[0] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/lives/lost_health.xpm");
	window->settings.health[1] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/lives/red_health.xpm");
}

void	echo(char *name, char *arg)
{
	system(ft_strjoin("echo ", ft_strjoin(name, arg)));
}

void	stats(t_window *window)
{
	system("clear");
	echo("========== STATS ==========", "");
	echo("Map        : ",
		window->game.maps[window->game.current_level].level_name);
	echo("Level      : ", ft_itoa(window->game.current_level + 1));
	echo("", "");
	echo("Lives      : ", ft_itoa(window->player.lives));
	echo("Position X : ", ft_itoa(window->player.x));
	echo("Position Y : ", ft_itoa(window->player.y));
}
