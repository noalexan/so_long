/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:28:15 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/22 12:41:00 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_key_event(int key, t_window *window)
{
	if (key == 53)
		mlx_destroy_window(window->mlx, window->win);
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
	ft_put_walls(window);
	ft_put_player(window);
	return (0);
}

int	main(void)
{
	t_window	window;

	window.width = 640;
	window.height = 460;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.height, "SL");
	ft_fill_floor(&window);
	ft_put_walls(&window);
	window.player.sprites.north = mlx_xpm_file_to_image(window.mlx,
			"lib/sprites/player/player_north.xpm", &window.player.width,
			&window.player.height);
	window.player.sprites.east = mlx_xpm_file_to_image(window.mlx,
			"lib/sprites/player/player_east.xpm", &window.player.width,
			&window.player.height);
	window.player.sprites.south = mlx_xpm_file_to_image(window.mlx,
			"lib/sprites/player/player_south.xpm", &window.player.width,
			&window.player.height);
	window.player.sprites.west = mlx_xpm_file_to_image(window.mlx,
			"lib/sprites/player/player_west.xpm", &window.player.width,
			&window.player.height);
	window.player.sprites.facing = 'E';
	ft_put_player(&window);
	mlx_hook(window.win, 2, 1L << 2, ft_key_event, &window);
	mlx_loop(window.mlx);
	return (0);
}
