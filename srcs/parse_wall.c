/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:30:10 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/03 09:14:35 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	parse_content(t_window *window, int level_num)
{
	int	i;
	int	j;

	i = -1;
	while (window->game.maps[level_num].board[++i])
	{
		j = -1;
		while (window->game.maps[level_num].board[i][++j])
			if (window->game.maps[level_num].board[i][j] != '1'
				&& window->game.maps[level_num].board[i][j] != '0'
				&& window->game.maps[level_num].board[i][j] != 'P'
				&& window->game.maps[level_num].board[i][j] != 'E'
				&& window->game.maps[level_num].board[i][j] != 'C'
				&& window->game.maps[level_num].board[i][j] != 'Q'
				&& window->game.maps[level_num].board[i][j] != '\n')
				err("la map '%s' contient des elements indesirables.",
					window->game.maps[level_num].level_name);
	}
	set_exit(window, level_num);
}

void	parse_wall(t_window *window, int level_num)
{
	int	i;
	int	j;

	i = -1;
	while (window->game.maps[level_num].board[0][++i])
		if (window->game.maps[level_num].board[0][i] != '1'
			&& window->game.maps[level_num].board[0][i] != '\n')
			err("les bords de la map '%s' sont invalide.", window->game
				.maps[level_num].level_name);
	i = -1;
	while (window->game.maps[level_num].board[++i])
		if (window->game.maps[level_num].board[i][0] != '1'
			|| window->game.maps[level_num].board[i][ft_strlen(window->game
				.maps[level_num].board[i]) - 2] != '1'
			|| window->game.maps[level_num].board[i][ft_strlen(window->game
				.maps[level_num].board[i]) - 1] != '\n')
			err("les bords de la map '%s' sont invalide.", window->game
				.maps[level_num].level_name);
	j = -1;
	while (window->game.maps[level_num].board[i - 1][++j])
		if (window->game.maps[level_num].board[i - 1][j] != '1'
			&& window->game.maps[level_num].board[i - 1][j] != '\n')
			err("les bords de la map '%s' sont invalide.", window->game
				.maps[level_num].level_name);
	parse_content(window, level_num);
}
