/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:48:12 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/26 11:17:04 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_over(t_window *window)
{
	window->settings.max_lives++;
	mlx_clear_window(window->mlx, window->win);
	mlx_string_put(window->mlx, window->win,
		window->game.maps[window->game.current_level].width / 2 - 45,
		window->game.maps[window->game.current_level].heigth / 2 - 5,
		mlx_get_color_value(window->mlx, window->settings.gameover_title_color),
		"Game Over");
	mlx_destroy_window(window->mlx, window->win);
	init_game(window);
}
