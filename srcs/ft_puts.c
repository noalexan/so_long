/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:35:23 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/25 19:28:31 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_put_player(t_window *window)
{
	if (window->player.sprites.facing == 'N')
		mlx_put_image_to_window(window->mlx,
			window->win, window->player.sprites.north,
			window->player.x, window->player.y);
	else if (window->player.sprites.facing == 'S')
		mlx_put_image_to_window(window->mlx,
			window->win, window->player.sprites.south,
			window->player.x, window->player.y);
	else if (window->player.sprites.facing == 'E')
		mlx_put_image_to_window(window->mlx,
			window->win, window->player.sprites.east,
			window->player.x, window->player.y);
	else if (window->player.sprites.facing == 'W')
		mlx_put_image_to_window(window->mlx,
			window->win, window->player.sprites.west,
			window->player.x, window->player.y);
}

void	ft_put_health(t_window *window)
{
	void	*lost_health;
	void	*red_health;
	int		w;
	int		h;
	int		i;

	i = 0;
	lost_health = mlx_xpm_file_to_image(window->mlx,
			window->settings.health[0], &w, &h);
	red_health = mlx_xpm_file_to_image(window->mlx,
			window->settings.health[1], &w, &h);
	while (++i <= window->settings.max_lives)
	{
		if (window->player.lives >= i)
			mlx_put_image_to_window(window->mlx, window->win, red_health,
				window->game.maps[window->game.current_level].width - 16 * i,
				2);
		else
			mlx_put_image_to_window(window->mlx, window->win, lost_health,
				window->game.maps[window->game.current_level].width - 16 * i,
				2);
	}
	if (window->player.lives < 1)
		game_over(window);
}

void	ft_fill_floor(t_window *window)
{
	void	*image;
	int		x;
	int		y;
	int		w;
	int		h;

	image = mlx_xpm_file_to_image(window->mlx, window->settings.floor,
			&w, &h);
	x = 0;
	while (x <= window->game.maps[window->game.current_level].width)
	{
		y = 0;
		while (y <= window->game.maps[window->game.current_level].heigth)
		{
			mlx_put_image_to_window(window->mlx, window->win, image, x, y);
			y += 16;
		}
		x += 16;
	}
}

void	ft_put_walls(t_window *win)
{
	void	*img;
	int		x;
	int		y;
	int		b[4];

	img = mlx_xpm_file_to_image(win->mlx, win->settings.wall, &x, &y);
	b[0] = 1;
	b[2] = win->game.maps[win->game.current_level].heigth / 16;
	b[3] = 0;
	b[1] = (win->game.maps[win->game.current_level].width - 1) / 16;
	y = b[0];
	while (y <= b[2])
	{
		x = b[3];
		while (x <= b[1])
		{
			if (((x == b[3] || x == b[1]) && b[0] <= y && y <= b[2])
				|| ((y == b[0] || y == b[2]) && b[1] >= x && x >= b[3]))
				mlx_put_image_to_window(win->mlx, win->win, img,
					x * 16 - 7, y * 16 - 6);
			x++;
		}
		y++;
	}
}

void	ft_move(char facing, t_window *window)
{
	window->player.sprites.facing = facing;
	window->player.lives--;
	if (!its_a_wall(window))
	{
		if (facing == 'N')
			window->player.y -= window->player.speed;
		else if (facing == 'S')
			window->player.y += window->player.speed;
		else if (facing == 'E')
			window->player.x += window->player.speed;
		else if (facing == 'W')
			window->player.x -= window->player.speed;
	}
}
