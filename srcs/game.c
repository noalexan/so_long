/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:52:53 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 15:54:05 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_destroy_win(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_key_event(int key, t_window *window)
{
	if (key == 53)
		ft_destroy_win(window);
	else if (key == 49)
		window->player.lives--;
	else if (key == 13 || key == 126)
		ft_move('N', window);
	else if (key == 0 || key == 123)
		ft_move('W', window);
	else if (key == 1 || key == 125)
		ft_move('S', window);
	else if (key == 2 || key == 124)
		ft_move('E', window);
	else
		return (0);
	print_map(window);
	return (0);
}
