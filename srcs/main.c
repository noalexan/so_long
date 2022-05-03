/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:28:15 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/03 09:07:30 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_window	window;

	(void) argc;
	settings(&window);
	init_map(&window, argv + 1);
	window.player.lives = window.settings.max_lives;
	window.mlx = mlx_init();
	init_game(&window);
	mlx_loop(window.mlx);
	return (0);
}
