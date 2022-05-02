/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:51:59 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/02 14:37:13 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	get_rand_facing(void)
{
	char	facing;

	facing = rand() % 4;
	if (facing == 0)
		return ('N');
	else if (facing == 1)
		return ('E');
	else if (facing == 2)
		return ('S');
	else
		return ('W');
}

char	its_a_wall_ennemies_2(t_window *window, int i)
{
	if (window->game.maps[window->game.current_level].ennemies[i].sprites
		.facing == 'W')
		return (window->game.maps[window->game.current_level].board[window->game
				.maps[window->game.current_level].ennemies[i]
				.y / 16 - 1][window->game.maps[window->game.current_level]
			.ennemies[i].x / 16 - 1]);
	else if (window->game.maps[window->game.current_level].ennemies[i].sprites
		.facing == 'E')
		return (window->game.maps[window->game.current_level].board[window->game
				.maps[window->game.current_level].ennemies[i]
				.y / 16 - 1][window->game.maps[window->game.current_level]
			.ennemies[i].x / 16 + 1]);
	return (1);
}

int	its_a_wall_ennemies(t_window *window, int i)
{
	int	res;

	res = 0;
	if (window->game.maps[window->game.current_level].ennemies[i]
		.sprites.facing == 'N')
		res = window->game.maps[window->game.current_level].board[window->game
			.maps[window->game.current_level].ennemies[i]
			.y / 16 - 2][window->game.maps[window->game.current_level
		].ennemies[i].x / 16];
	else if (window->game.maps[window->game.current_level].ennemies[i].sprites
		.facing == 'S')
		res = window->game.maps[window->game.current_level].board[window->game
			.maps[window->game.current_level].ennemies[i]
			.y / 16][window->game.maps[window->game.current_level].ennemies[i]
			.x / 16];
	else
		res = its_a_wall_ennemies_2(window, i);
	if (res == 'P')
		return (1);
	return (res - '0');
}

void	ft_put_ennemies(t_window *w, int i)
{
	if (w->game.maps[w->game.current_level].ennemies[i].sprites.facing == 'N')
		mlx_put_image_to_window(w->mlx, w->win, w->game.maps[w->game
			.current_level].ennemies[i].sprites.north, w->game.maps[w->game
			.current_level].ennemies[i].x, w->game.maps[w->game.current_level]
			.ennemies[i].y);
	else if (w->game.maps[w->game.current_level].ennemies[i].sprites.facing
		== 'S')
		mlx_put_image_to_window(w->mlx, w->win, w->game.maps[w->game
			.current_level].ennemies[i].sprites.south,
			w->game.maps[w->game.current_level].ennemies[i].x,
			w->game.maps[w->game.current_level].ennemies[i].y);
	else if (w->game.maps[w->game.current_level].ennemies[i].sprites
		.facing == 'E')
		mlx_put_image_to_window(w->mlx, w->win, w->game.maps[w->game
			.current_level].ennemies[i].sprites.east, w->game.maps[w->game
			.current_level].ennemies[i].x, w->game.maps[w->game.current_level]
			.ennemies[i].y);
	else if (w->game.maps[w->game.current_level].ennemies[i].sprites
		.facing == 'W')
		mlx_put_image_to_window(w->mlx,
			w->win, w->game.maps[w->game.current_level]
			.ennemies[i].sprites.west,
			w->game.maps[w->game.current_level].ennemies[i].x,
			w->game.maps[w->game.current_level].ennemies[i].y);
}

void	ft_move_ennemies(t_window *window, int i)
{
	char	f;
	int		o;

	o = -1;
	f = get_rand_facing();
	window->game.maps[window->game.current_level].ennemies[i].sprites.facing
		= f;
	while (its_a_wall_ennemies(window, i) && ++o < 5)
	{
		f = get_rand_facing();
		window->game.maps[window->game.current_level].ennemies[i].sprites.facing
			= f;
	}
	if (o < 5)
	{
		map_objs_swap_ennemies(window, i);
		if (f == 'N')
			window->game.maps[window->game.current_level].ennemies[i].y -= 16;
		else if (f == 'S')
			window->game.maps[window->game.current_level].ennemies[i].y += 16;
		else if (f == 'E')
			window->game.maps[window->game.current_level].ennemies[i].x += 16;
		else if (f == 'W')
			window->game.maps[window->game.current_level].ennemies[i].x -= 16;
	}
}
