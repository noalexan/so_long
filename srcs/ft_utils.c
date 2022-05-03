/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:08:56 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/03 08:53:33 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	special_char(t_window *window, char res)
{
	if (res == 'E')
	{
		if (!window->game.maps[window->game.current_level].exit)
			end_of_level(window);
		return (1);
	}
	else if (res == 'Q')
	{
		window->player.lives--;
		return (1);
	}
	else if (res == 'C')
		window->game.maps[window->game.current_level].exit--;
	return (0);
}

int	its_a_wall(t_window *window)
{
	int	res;

	res = 0;
	if (window->player.sprites.facing == 'N')
		res = window->game.maps[window->game.current_level].board[window->player
			.y / 16 - 2][window->player.x / 16];
	else if (window->player.sprites.facing == 'S')
		res = window->game.maps[window->game.current_level].board[window->player
			.y / 16][window->player.x / 16];
	else if (window->player.sprites.facing == 'W')
		res = window->game.maps[window->game.current_level].board[window->player
			.y / 16 - 1][window->player.x / 16 - 1];
	else if (window->player.sprites.facing == 'E')
		res = window->game.maps[window->game.current_level].board[window->player
			.y / 16 - 1][window->player.x / 16 + 1];
	if (res == 'P' || res == 'C' || res == 'E' || res == 'Q')
		return (special_char(window, res));
	return (res - '0');
}

void	map_spawn_is_valid(t_window *window, int i)
{
	int	x;
	int	y;
	int	p;

	y = -1;
	p = 0;
	while (window->game.maps[i].board[++y])
	{
		x = -1;
		while (window->game.maps[i].board[y][++x])
		{
			if (window->game.maps[i]
				.board[y][x] == 'P')
			{
				window->game.maps[i].x_pos = x * 16;
				window->game.maps[i].y_pos = y * 16 + 16;
				p++;
			}
		}
	}
	if (p != 1)
		err("le spawn de la map '%s' est invalide.", window->game
			.maps[i].level_name);
}

void	map_exit_is_valid(t_window *window, int i)
{
	int	x;
	int	y;
	int	e;
	int	ennemies;

	y = -1;
	e = 0;
	ennemies = 0;
	while (window->game.maps[i].board[++y])
	{
		x = -1;
		while (window->game.maps[i].board[y][++x])
		{
			if (window->game.maps[i]
				.board[y][x] == 'E')
				e++;
			else if (window->game.maps[i]
				.board[y][x] == 'Q')
				ennemies++;
		}
	}
	if (e < 1)
		err("la map '%s' ne presente aucune sortie.", window->game
			.maps[i].level_name);
	window->game.maps[i].nb_of_ennemies = ennemies;
}

void	map_is_valid(t_window *window)
{
	int	i;

	i = -1;
	while (++i < window->game.level)
	{
		map_spawn_is_valid(window, i);
		map_exit_is_valid(window, i);
	}
}
