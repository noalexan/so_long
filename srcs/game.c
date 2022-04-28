/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:52:53 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 10:02:42 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_destroy_win(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_key_event(int key, t_window *window)
{
	if (key == 53)
		ft_destroy_win(window);
	else if (key == 49)
		window->player.lives--;
	else if (key == 13 || key == 126)
		ft_move('N', window);
	else if (key == 0 || key == 123)
		ft_move('W', window);
	else if (key == 1 || key == 125)
		ft_move('S', window);
	else if (key == 2 || key == 124)
		ft_move('E', window);
	else
		return (0);
	mlx_clear_window(window->mlx, window->win);
	ft_fill_floor(window);
	place_objects(window);
	ft_put_player(window);
	mlx_string_put(window->mlx, window->win, 2, -2,
		mlx_get_color_value(window->mlx, window->settings.level_title_color),
		"Level");
	ft_put_health(window);
	stats(window);
	return (0);
}

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

void	init_game(t_window *window)
{
	window->game.current_level++;
	if (window->player.lives < window->settings.max_lives)
		window->player.lives += window->settings.live_regain;
	if (window->game.current_level >= window->game.level)
		exit(EXIT_SUCCESS);
	window->win = mlx_new_window(window->mlx,
			window->game.maps[window->game.current_level].width
			* window->settings.nogui,
			window->game.maps[window->game.current_level].heigth + 20
			* window->settings.nogui,
			window->settings.window_title);
	ft_fill_floor(window);
	place_objects(window);
	init_player(window);
	mlx_string_put(window->mlx, window->win, 2, -2,
		mlx_get_color_value(window->mlx, window->settings.level_title_color),
		"Level");
	ft_put_health(window);
	mlx_hook(window->win, 2, 1L << 2, ft_key_event, window);
	mlx_hook(window->win, 17, 1L << 2, ft_destroy_win, window);
	stats(window);
}
