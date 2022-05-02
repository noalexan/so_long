/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:35:23 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/02 11:25:27 by noalexan         ###   ########.fr       */
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
		end_of_level(window);
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
		while (y - 16 <= window->game.maps[window->game.current_level].heigth)
		{
			mlx_put_image_to_window(window->mlx, window->win, image, x, y);
			y += 16;
		}
		x += 16;
	}
}

void	ft_move(char facing, t_window *window)
{
	window->player.sprites.facing = facing;
	if (!its_a_wall(window))
	{
		window->game.maps[window->game.current_level].count++;
		map_objs_swap(window);
		if (facing == 'N')
			window->player.y -= window->settings.speed;
		else if (facing == 'S')
			window->player.y += window->settings.speed;
		else if (facing == 'E')
			window->player.x += window->settings.speed;
		else if (facing == 'W')
			window->player.x -= window->settings.speed;
	}
}
