/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:30:15 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/29 14:06:01 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_swap(char *a, char *b)
{
	*a = '0';
	*b = 'P';
}

void	ft_swap_ennemies(char *a, char *b)
{
	*a = '0';
	*b = 'Q';
}

void	map_objs_swap(t_window *window)
{
	if (window->player.sprites.facing == 'N')
		ft_swap(&window->game.maps[window->game.current_level]
			.board[window->player.y / 16 - 1][window->player.x / 16],
			&window->game.maps[window->game.current_level]
			.board[window->player.y / 16 - 2][window->player.x / 16]);
	else if (window->player.sprites.facing == 'S')
		ft_swap(&window->game.maps[window->game.current_level]
			.board[window->player.y / 16 - 1][window->player.x / 16],
			&window->game.maps[window->game.current_level]
			.board[window->player.y / 16][window->player.x / 16]);
	else if (window->player.sprites.facing == 'E')
		ft_swap(&window->game.maps[window->game.current_level]
			.board[window->player.y / 16 - 1][window->player.x / 16],
			&window->game.maps[window->game.current_level]
			.board[window->player.y / 16 - 1][window->player.x / 16 + 1]);
	else if (window->player.sprites.facing == 'W')
		ft_swap(&window->game.maps[window->game.current_level]
			.board[window->player.y / 16 - 1][window->player.x / 16],
			&window->game.maps[window->game.current_level]
			.board[window->player.y / 16 - 1][window->player.x / 16 - 1]);
}

void	map_objs_swap_ennemies_2(t_window *window, int i)
{
	if (window->game.maps[window->game.current_level].ennemies[i].sprites
		.facing == 'E')
		ft_swap_ennemies(&window->game.maps[window->game.current_level]
			.board[window->game.maps[window->game.current_level].ennemies[i].y
			/ 16 - 1][window->game.maps[window->game.current_level].ennemies[i]
			.x / 16],
			&window->game.maps[window->game.current_level]
			.board[window->game.maps[window->game.current_level].ennemies[i].y
			/ 16 - 1][window->game.maps[window->game.current_level].ennemies[i]
			.x / 16 + 1]);
	else if (window->game.maps[window->game.current_level].ennemies[i].sprites
		.facing == 'W')
		ft_swap_ennemies(&window->game.maps[window->game.current_level]
			.board[window->game.maps[window->game.current_level].ennemies[i].y
			/ 16 - 1][window->game.maps[window->game.current_level].ennemies[i]
			.x / 16],
			&window->game.maps[window->game.current_level]
			.board[window->game.maps[window->game.current_level].ennemies[i].y
			/ 16 - 1][window->game.maps[window->game.current_level].ennemies[i]
			.x / 16 - 1]);
}

void	map_objs_swap_ennemies(t_window *window, int i)
{
	if (window->game.maps[window->game.current_level].ennemies[i].sprites
		.facing == 'N')
		ft_swap_ennemies(&window->game.maps[window->game.current_level]
			.board[window->game.maps[window->game.current_level].ennemies[i].y
			/ 16 - 1][window->game.maps[window->game.current_level].ennemies[i]
			.x / 16],
			&window->game.maps[window->game.current_level]
			.board[window->game.maps[window->game.current_level].ennemies[i].y
			/ 16 - 2][window->game.maps[window->game.current_level].ennemies[i]
			.x / 16]);
	else if (window->game.maps[window->game.current_level].ennemies[i].sprites
		.facing == 'S')
		ft_swap_ennemies(&window->game.maps[window->game.current_level]
			.board[window->game.maps[window->game.current_level].ennemies[i].y
			/ 16 - 1][window->game.maps[window->game.current_level].ennemies[i]
			.x / 16],
			&window->game.maps[window->game.current_level]
			.board[window->game.maps[window->game.current_level].ennemies[i].y
			/ 16][window->game.maps[window->game.current_level].ennemies[i]
			.x / 16]);
	else
		map_objs_swap_ennemies_2(window, i);
}
