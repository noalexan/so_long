/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:20:42 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 14:38:45 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collectibles(t_window *win, int i)
{
	void	*img;
	int		x;
	int		y;
	int		w;
	int		h;

	print_map(win);
	img = mlx_xpm_file_to_image(win->mlx, win->settings.collectibles[i],
			&w, &h);
	y = -1;
	while (win->game.maps[win->game.current_level].board[++y])
	{
		x = -1;
		while (win->game.maps[win->game.current_level].board[y][++x])
			if (win->game.maps[win->game.current_level].board[y][x] == 'C')
				mlx_put_image_to_window(win->mlx, win->win, img,
					x * 16, y * 16 + 19);
	}
}

void	animate_collectibles(t_window *window, int *c)
{
	if (*c / window->settings.collectibles_frame_speed == 1
		&& *c % window->settings.collectibles_frame_speed == 0)
		collectibles(window, 0);
	else if (*c / (window->settings.collectibles_frame_speed * 2) == 1
		&& *c % (window->settings.collectibles_frame_speed * 2) == 0)
		collectibles(window, 1);
	else if (*c / (window->settings.collectibles_frame_speed * 3) == 1
		&& *c % (window->settings.collectibles_frame_speed * 3) == 0)
	{
		collectibles(window, 2);
		*c = 0;
	}
}

void	animate_ennemies(t_window *window, int *e)
{
	int	d;
	// int	i;

	if (*e / window->settings.ennemies_frame_speed == 1
		&& *e % window->settings.ennemies_frame_speed == 0)
	{
		// i = -1;
		// while (window->game.maps[++i])
		// {
			d = rand() % 4;
			ft_printf("%d", d);
		// }
		*e = 0;
	}
}

int	animate(t_window *window)
{
	static int	collectibles = 0;
	static int	ennemies = 0;

	animate_collectibles(window, &collectibles);
	animate_ennemies(window, &ennemies);
	collectibles++;
	ennemies++;
	return (0);
}
