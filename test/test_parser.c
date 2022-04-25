/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:15:16 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/25 12:58:44 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_maps(char **levels)
{
	int	i;

	i = -1;
	ft_printf("maps:\n");
	while (levels[++i])
		ft_printf("  %s\n", levels[i]);
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_window	window;
	int			i;
	int			j;

	init_map(&window, argv + 1);
	ft_print_maps(argv + 1);
	i = -1;
	while (argc > ++i + 1)
	{
		j = -1;
		ft_printf("map '%s':\t(%dx%d)\n",
			window.game.maps[i].level_name,
			window.game.maps[i].width,
			window.game.maps[i].heigth);
		while (window.game.maps[i].board[++j])
			ft_printf("%s\n", window.game.maps[i].board[j]);
		ft_printf("\n");
	}
	exit(EXIT_SUCCESS);
}
