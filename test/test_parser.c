/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:15:16 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 17:17:00 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_list_of_maps(char **maps)
{
	int	i;

	i = -1;
	ft_printf("maps:\n");
	while (maps[++i])
		ft_printf("  %s\n", maps[i]);
}

int	main(int argc, char **argv)
{
	t_window	window;
	int			i;
	int			j;

	i = -1;
	j = -1;
	(void) argc;
	init_map(&window, argv + 1);
	print_list_of_maps(argv + 1);
	while (window.game.board[++i])
		while (window.game.board[i][++j])
			ft_printf("board[%d][%d] = %s", i, j, window.game.board[0][0]);
	exit(EXIT_FAILURE);
}
