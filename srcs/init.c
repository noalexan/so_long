/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:33:54 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/29 12:15:35 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_player(t_window *window)
{
	window->player.x = window->game.maps[window->game.current_level].x_pos;
	window->player.y = window->game.maps[window->game.current_level].y_pos;
	window->player.sprites.north = mlx_xpm_file_to_image(window->mlx,
			window->settings.player[0], &window->player.width,
			&window->player.height);
	window->player.sprites.east = mlx_xpm_file_to_image(window->mlx,
			window->settings.player[1], &window->player.width,
			&window->player.height);
	window->player.sprites.south = mlx_xpm_file_to_image(window->mlx,
			window->settings.player[2], &window->player.width,
			&window->player.height);
	window->player.sprites.west = mlx_xpm_file_to_image(window->mlx,
			window->settings.player[3], &window->player.width,
			&window->player.height);
	window->player.sprites.facing = 'S';
	ft_put_player(window);
}

void	init_ennemie(t_window *win, int i, int x, int y)
{
	win->game.maps[win->game.current_level].ennemies[i].x = x;
	win->game.maps[win->game.current_level].ennemies[i].y = y;
	win->game.maps[win->game.current_level].ennemies[i].sprites.north
		= mlx_xpm_file_to_image(win->mlx,
			win->settings.ennemies[0], &win->game.maps[win->game
			.current_level].ennemies[i].width,
			&win->game.maps[win->game.current_level].ennemies[i].height);
	win->game.maps[win->game.current_level].ennemies[i].sprites.east
		= mlx_xpm_file_to_image(win->mlx,
			win->settings.ennemies[1], &win->game.maps[win->game
			.current_level].ennemies[i].width,
			&win->game.maps[win->game.current_level].ennemies[i].height);
	win->game.maps[win->game.current_level].ennemies[i].sprites.south
		= mlx_xpm_file_to_image(win->mlx,
			win->settings.ennemies[2], &win->game.maps[win->game
			.current_level].ennemies[i].width,
			&win->game.maps[win->game.current_level].ennemies[i].height);
	win->game.maps[win->game.current_level].ennemies[i].sprites.west
		= mlx_xpm_file_to_image(win->mlx,
			win->settings.ennemies[3], &win->game.maps[win->game
			.current_level].ennemies[i].width,
			&win->game.maps[win->game.current_level].ennemies[i].height);
	win->game.maps[win->game.current_level].ennemies[i].sprites.facing
		= 'S';
}

void	init_ennemies(t_window *win)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = -1;
	win->game.maps[win->game.current_level].ennemies = ft_calloc(win->game
			.maps[win->game.current_level].nb_of_ennemies, sizeof(t_ennemies));
	while (win->game.maps[win->game.current_level].board[++y])
	{
		x = -1;
		while (win->game.maps[win->game.current_level].board[y][++x])
		{
			if (win->game.maps[win->game.current_level].board[y][x] == 'Q')
			{
				init_ennemie(win, i, x * 16, (y + 1) * 16);
				i++;
			}
		}
	}
}

void	init_game(t_window *window)
{
	window->game.current_level++;
	if (window->player.lives > 0 && window->player.lives < window->settings
		.max_lives)
		window->player.lives += window->settings.live_regain;
	if (window->game.current_level >= window->game.level)
		exit(EXIT_SUCCESS);
	window->win = mlx_new_window(window->mlx,
			window->game.maps[window->game.current_level].width
			* window->settings.nogui,
			window->game.maps[window->game.current_level].heigth + 20
			* window->settings.nogui,
			window->settings.window_title);
	init_player(window);
	init_ennemies(window);
	print_map(window);
	mlx_hook(window->win, 2, 1L << 2, ft_key_event, window);
	mlx_hook(window->win, 17, 1L << 2, ft_destroy_win, window);
	mlx_loop_hook(window->mlx, animate, window);
}

void	init_map(t_window *window, char **levels)
{
	int	size;
	int	i;

	window->player.armed = 0;
	size = size_of_tab((void *) levels);
	if (size < 1)
		err("veuillez entrer une ou plusieurs maps en argument.");
	if (!ft_strcmp(levels[size - 1], "--nogui") || !ft_strcmp(levels[size - 1],
			"-n"))
	{
		window->settings.nogui = 0;
		size--;
	}
	window->game.level = size;
	window->game.current_level = -1;
	window->game.maps = ft_calloc(size, sizeof(t_map));
	i = -1;
	while (++i < size)
		parse_map(window, levels[i], i);
	map_is_valid(window);
}
