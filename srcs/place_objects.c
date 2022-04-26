/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:18:08 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/26 14:24:41 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	place_objects(t_window *window)
{
	int		x;
	int		y;
	char	obj;

	if (!window->settings.nogui)
	{
		y = -1;
		while (window->game.maps[window->game.current_level].board[++y])
		{
			x = -1;
			while (window->game.maps[window->game.current_level].board[y][++x])
			{
				obj = window->game
					.maps[window->game.current_level].board[y][x];
				if (obj == '1')
					ft_put_walls(window, x * 16, y * 16);
			}
		}
	}
}
