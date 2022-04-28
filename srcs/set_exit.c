/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:46:05 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 13:05:36 by noalexan         ###   ########.fr       */
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
