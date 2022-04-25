/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:08:56 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/25 18:18:54 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	its_a_wall(t_window *window)
{
	ft_printf("pos x\t: %d,\npos y\t: %d\n", window->player.x, window->player.y);
	if ((window->player.sprites.facing == 'W'
			&& window->player.x - window->player.speed < 0)
		|| (window->player.sprites.facing == 'N'
			&& window->player.y - window->player.speed < 0)
		|| (window->player.sprites.facing == 'E'
			&& window->player.x + window->player.speed + 64
			< window->game.maps[window->game.current_level].width)
		|| (window->player.sprites.facing == 'S'
			&& window->player.y + window->player.speed + 64
			< window->game.maps[window->game.current_level].heigth))
	{
		ft_printf("It's a wall\n");
		return (1);
	}
	ft_printf("\n");
	return (0);
}
