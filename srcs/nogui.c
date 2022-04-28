/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nogui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:53:32 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 11:35:42 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_nogui_legend(t_window *window)
{
	ft_printf("\nPlayer: %s  Collectibles: %s\nExit:   %s  Weapon:       %s\n",
		window->settings.nogui_color.player,
		window->settings.nogui_color.collectibles,
		window->settings.nogui_color.exit,
		window->settings.nogui_color.weapons);
}

void	print_what_you_want(t_window *window, int i, int j)
{
	if (window->game.maps[window->game.current_level]
		.board[i][j] == '1')
		ft_printf(window->settings.nogui_color.wall);
	else if (window->game.maps[window->game.current_level]
		.board[i][j] == 'P')
		ft_printf(window->settings.nogui_color.player);
	else if (window->game.maps[window->game.current_level]
		.board[i][j] == 'E')
		ft_printf(window->settings.nogui_color.exit);
	else if (window->game.maps[window->game.current_level]
		.board[i][j] == 'C')
		ft_printf(window->settings.nogui_color.collectibles);
	else if (window->game.maps[window->game.current_level]
		.board[i][j] == 'W')
		ft_printf(window->settings.nogui_color.weapons);
	else if (window->game.maps[window->game.current_level]
		.board[i][j] == '0')
		ft_printf(window->settings.nogui_color.floor);
}

void	print_nogui_map(t_window *window)
{
	int	i;
	int	j;

	i = -1;
	while (window->game.maps[window->game.current_level].board[++i])
	{
		j = -1;
		while (window->game.maps[window->game.current_level].board[i][++j])
			print_what_you_want(window, i, j);
		ft_printf("\n");
	}
	print_nogui_legend(window);
}
