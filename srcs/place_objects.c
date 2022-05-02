/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:18:08 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/02 12:38:51 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	door(t_window *win)
{
	void	*img;
	int		x;
	int		y;
	int		w;
	int		h;

	if (!win->game.maps[win->game.current_level].exit)
		img = mlx_xpm_file_to_image(win->mlx, win->settings.door[1], &w, &h);
	else
		img = mlx_xpm_file_to_image(win->mlx, win->settings.door[0], &w, &h);
	y = -1;
	while (win->game.maps[win->game.current_level].board[++y])
	{
		x = -1;
		while (win->game.maps[win->game.current_level].board[y][++x])
			if (win->game.maps[win->game.current_level].board[y][x] == 'E')
				mlx_put_image_to_window(win->mlx, win->win, img,
					x * 16 + 1, y * 16 + 19);
	}
}

void	place_weapons(t_window *win)
{
	void	*img;
	int		x;
	int		y;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(win->mlx, win->settings.weapon[0], &w, &h);
	y = -1;
	while (win->game.maps[win->game.current_level].board[++y])
	{
		x = -1;
		while (win->game.maps[win->game.current_level].board[y][++x])
			if (win->game.maps[win->game.current_level].board[y][x] == 'W')
				mlx_put_image_to_window(win->mlx, win->win, img,
					x * 16 + 1, y * 16 + 19);
	}
}

void	put_walls(t_window *win)
{
	void	*img;
	int		x;
	int		y;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(win->mlx, win->settings.wall, &w, &h);
	y = -1;
	while (win->game.maps[win->game.current_level].board[++y])
	{
		x = -1;
		while (win->game.maps[win->game.current_level].board[y][++x])
			if (win->game.maps[win->game.current_level].board[y][x] == '1')
				mlx_put_image_to_window(win->mlx, win->win, img,
					x * 16 - 7, y * 16 + 10);
	}
}

void	place_objects(t_window *window)
{
	put_walls(window);
	door(window);
	place_weapons(window);
}
