/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:35:23 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 18:34:24 by noalexan         ###   ########.fr       */
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

void	ft_fill_floor(t_window *window)
{
	void	*image;
	int		x;
	int		y;
	int		w;
	int		h;

	image = mlx_xpm_file_to_image(window->mlx, "lib/sprites/wooden.xpm",
			&w, &h);
	x = 0;
	while (x <= 624)
	{
		y = 0;
		while (y <= 460)
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

	img = mlx_xpm_file_to_image(win->mlx, "lib/sprites/fence.xpm", &x, &y);
	b[0] = 0;
	b[2] = (win->height - 1) / 16;
	b[3] = 0;
	b[1] = (win->width - 1) / 16;
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
	int	speed;

	speed = 10;
	if (facing == 'N')
		window->player.y -= speed;
	else if (facing == 'S')
		window->player.y += speed;
	else if (facing == 'E')
		window->player.x += speed;
	else if (facing == 'W')
		window->player.x -= speed;
	window->player.sprites.facing = facing;
	ft_put_player(window);
}
