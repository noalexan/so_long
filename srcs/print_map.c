/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:26:53 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 14:28:34 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
	ft_fill_floor(window);
	place_objects(window);
	ft_put_player(window);
	print_level(window);
	ft_put_health(window);
	stats(window);
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
