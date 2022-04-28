/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:51:59 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 17:32:43 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	get_rand_facing(void)
{
	char	facing;

	facing = rand() % 4;
	ft_printf("%d\n", facing);
	if (facing == 0)
		return ('N');
	else if (facing == 1)
		return ('E');
	else if (facing == 2)
		return ('S');
	else
		return ('W');
}

int	its_a_wall_ennemies_2(t_window *window, int i)
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
		return (special_char(window, res));
	return (res - '0');
}

void	ft_put_ennemies(t_window *window, int i)
{
	if (window->game.maps[window->game.current_level].ennemies[i].sprites
		.facing == 'N')
		mlx_put_image_to_window(window->mlx,
			window->win, window->game.maps[window->game.current_level]
			.ennemies[i].sprites.north,
			window->game.maps[window->game.current_level].ennemies[i].x,
			window->game.maps[window->game.current_level].ennemies[i].y);
	else if (window->game.maps[window->game.current_level].ennemies[i].sprites
		.facing == 'S')
		mlx_put_image_to_window(window->mlx,
			window->win, window->game.maps[window->game.current_level]
			.ennemies[i].sprites.south,
			window->game.maps[window->game.current_level].ennemies[i].x,
			window->game.maps[window->game.current_level].ennemies[i].y);
	else if (window->game.maps[window->game.current_level].ennemies[i].sprites
		.facing == 'E')
		mlx_put_image_to_window(window->mlx,
			window->win, window->game.maps[window->game.current_level]
			.ennemies[i].sprites.east,
			window->game.maps[window->game.current_level].ennemies[i].x,
			window->game.maps[window->game.current_level].ennemies[i].y);
	else if (window->game.maps[window->game.current_level].ennemies[i].sprites
		.facing == 'W')
		mlx_put_image_to_window(window->mlx,
			window->win, window->game.maps[window->game.current_level]
			.ennemies[i].sprites.west,
			window->game.maps[window->game.current_level].ennemies[i].x,
			window->game.maps[window->game.current_level].ennemies[i].y);
}

void	ft_move_ennemies(t_window *window, int i)
{
	char	f;

	f = get_rand_facing();
	window->game.maps[window->game.current_level].ennemies[i].sprites.facing
		= f;
	while (!its_a_wall_ennemies(window, i))
	{
		f = get_rand_facing();
		window->game.maps[window->game.current_level].ennemies[i].sprites.facing
			= f;
	}
	if (f == 'N')
		window->game.maps[window->game.current_level].ennemies[i].y -= 16;
	else if (f == 'S')
		window->game.maps[window->game.current_level].ennemies[i].y += 16;
	else if (f == 'E')
		window->game.maps[window->game.current_level].ennemies[i].x += 16;
	else if (f == 'W')
		window->game.maps[window->game.current_level].ennemies[i].x -= 16;
	ft_printf("%c ennemie: %d\n", f, i);
	ft_put_ennemies(window, i);
}
