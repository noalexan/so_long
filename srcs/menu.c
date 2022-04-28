/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:48:12 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 12:18:45 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_over(t_window *window)
{
	if (!window->settings.nogui)
		ft_printf("\033[31mCongratulation\033[0m\n");
	else
	{
		mlx_clear_window(window->mlx, window->win);
		mlx_string_put(window->mlx, window->win,
			window->game.maps[window->game.current_level].width / 2 - 45,
			window->game.maps[window->game.current_level].heigth / 2 - 5,
			mlx_get_color_value(window->mlx, window->settings
				.gameover_title_color), "Game Over");
	}
	mlx_destroy_window(window->mlx, window->win);
	init_game(window);
}

void	congratulation(t_window *window)
{
	if (!window->settings.nogui)
		ft_printf("\033[32mCongratulation\033[0m\n");
	else
	{
		mlx_clear_window(window->mlx, window->win);
		mlx_string_put(window->mlx, window->win,
			window->game.maps[window->game.current_level].width / 2 - 75,
			window->game.maps[window->game.current_level].heigth / 2 - 5,
			mlx_get_color_value(window->mlx, window->settings
				.success_title_color), "Congratulation !");
	}
	mlx_destroy_window(window->mlx, window->win);
	init_game(window);
}

void	end_of_level(t_window *window)
{
	if (window->player.lives < 1)
		game_over(window);
	else if (window->game.current_level >= window->game.level - 1)
		congratulation(window);
	else
	{
		mlx_destroy_window(window->mlx, window->win);
		init_game(window);
	}
}
