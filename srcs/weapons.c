/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:26:04 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/02 14:51:55 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	weapons(t_window *window)
{
	if (window->player.armed)
	{
		mlx_clear_window(window->mlx, window->win);
		mlx_put_image_to_window(window->mlx, window->win,
			window->player.arrow.sprites.east, 10, 10);
	}
}

void	init_arrow(t_window *window)
{
	window->player.arrow.sprites.north = mlx_xpm_file_to_image(window->mlx,
			window->settings.weapon[1], &window->player.arrow.width,
			&window->player.arrow.height);
	window->player.arrow.sprites.east = mlx_xpm_file_to_image(window->mlx,
			window->settings.weapon[2], &window->player.arrow.width,
			&window->player.arrow.height);
	window->player.arrow.sprites.south = mlx_xpm_file_to_image(window->mlx,
			window->settings.weapon[3], &window->player.arrow.width,
			&window->player.arrow.height);
	window->player.arrow.sprites.west = mlx_xpm_file_to_image(window->mlx,
			window->settings.weapon[4], &window->player.arrow.width,
			&window->player.arrow.height);
}
