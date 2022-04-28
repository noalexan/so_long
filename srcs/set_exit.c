/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:46:05 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 14:14:35 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_exit(t_window *window, int i)
{
	int		x;
	int		y;

	y = -1;
	window->game.maps[i].exit = 0;
	while (window->game.maps[i].board[++y])
	{
		x = -1;
		while (window->game.maps[i].board[y][++x])
			if (window->game.maps[i].board[y][x] == 'C')
				window->game.maps[i].exit++;
	}
	if (window->game.maps[i].exit < 1)
		err("la map '%s' ne presente aucun collectible.", window->game.maps[i]
			.level_name);
	y = -1;
	while (window->game.maps[i].board[++y])
	{
		x = -1;
		while (window->game.maps[i].board[y][++x])
			if (window->game.maps[i].board[y][x] == 'Q')
				window->game.maps[i].exit++;
	}
}

void	print_level(t_window *window)
{
	char	*level;
	char	*nb;

	nb = ft_itoa(window->game.current_level + 1);
	level = ft_strjoin("Level ", nb);
	free(nb);
	mlx_string_put(window->mlx, window->win, 2, -2,
		mlx_get_color_value(window->mlx, window->settings.level_title_color),
		level);
	free(level);
}
