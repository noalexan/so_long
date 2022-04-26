/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:08:56 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/26 15:49:08 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	if (res == 'P' || res == 'C' || res == 'E')
		return (0);
	return (res - '0');
}

		// if ((window->player.sprites.facing == 'N' && window->game
		// 	.maps[window->game.current_level]
		// 	.board[window->player.y / 16 + 1][window->player.x / 16] == 1)
		// || (window->player.sprites.facing == 'S' && window->game
		// 	.maps[window->game.current_level]
		// 	.board[window->player.y / 16 - 1][window->player.x / 16] == 1)
		// || (window->player.sprites.facing == 'W' && window->game
		// 	.maps[window->game.current_level]
		// 	.board[window->player.y / 16][window->player.x / 16 - 1] == 1)
		// || (window->player.sprites.facing == 'E' && window->game
		// 	.maps[window->game.current_level]
		// 	.board[window->player.y / 16][window->player.x / 16 + 1] == 1))
		// return (1);

	// if ((window->player.sprites.facing == 'W'
	// 		&& window->player.x - window->settings.speed <= 16)
	// 	|| (window->player.sprites.facing == 'N'
	// 		&& window->player.y - window->settings.speed < 16)
	// 	|| (window->player.sprites.facing == 'E'
	// 		&& window->player.x + window->settings.speed + 16
	// 		> window->game.maps[window->game.current_level].width)
	// 	|| (window->player.sprites.facing == 'S'
	// 		&& window->player.y + window->settings.speed + 16
	// 		> window->game.maps[window->game.current_level].heigth))