/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:27:34 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 13:54:16 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	settings_nogui(t_window *window)
{
	window->settings.nogui_color.wall = RED_BLOCK_CONSOLE;
	window->settings.nogui_color.floor = GREY_BLOCK_CONSOLE;
	window->settings.nogui_color.collectibles = YELLOW_BLOCK_CONSOLE;
	window->settings.nogui_color.exit = PINK_BLOCK_CONSOLE;
	window->settings.nogui_color.weapons = CYAN_BLOCK_CONSOLE;
	window->settings.nogui_color.player = BLUE_BLOCK_CONSOLE;
}

void	settings_string_2(t_window *window)
{
	window->settings.health[0] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/lives/lost_health.xpm");
	window->settings.health[1] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/lives/red_health.xpm");
	window->settings.door[0] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/doors/close.xpm");
	window->settings.door[1] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/doors/open.xpm");
	window->settings.weapon[0] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/weapons/bow.xpm");
	window->settings.weapon[1] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/weapons/arrow.xpm");
	window->settings.collectibles[0] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/collectibles/coin/coin_1.xpm");
	window->settings.collectibles[1] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/collectibles/coin/coin_2.xpm");
	window->settings.collectibles[2] = ft_strjoin(window->settings.dir_path,
			"lib/sprites/collectibles/coin/coin_3.xpm");
}

void	settings_string(t_window *window)
{
	window->settings.dir_path
		= "/Users/noalexan/Desktop/Projets42/42cursus/so_long/";
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
	settings_string_2(window);
}

void	settings(t_window *window)
{
	window->settings.max_lives = 3;
	window->settings.live_regain = 1;
	window->settings.speed = 16;
	window->settings.collectibles_frame_speed = 1024;
	window->settings.ennemies_frame_speed = 1024;
	window->settings.level_title_color = RED;
	window->settings.gameover_title_color = RED;
	window->settings.success_title_color = GREEN;
	window->settings.nogui = 1;
	window->settings.window_title = "So Long";
	settings_string(window);
	settings_nogui(window);
}

void	stats(t_window *window)
{
	system("clear");
	ft_printf("\e[31m============ STATS ============\e[0m\n");
	ft_printf("Map        : %s\n",
		window->game.maps[window->game.current_level].level_name);
	ft_printf("Level      : %d\n", window->game.current_level + 1);
	ft_printf("Lives      : %d\n", window->player.lives);
	if (window->player.armed)
		ft_printf("Armed      : Yes\n");
	else
		ft_printf("Armed      : No\n");
	ft_printf("Position X : %d\n", window->player.x);
	ft_printf("Position Y : %d\n\n", window->player.y);
	if (!window->settings.nogui)
		print_nogui_map(window);
}
