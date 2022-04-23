/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:06:58 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 18:03:19 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_window *window, char **levels)
{
	int	size;
	int	i;

	i = -1;
	size = ft_size_of_tab(levels);
	if (size < 1)
		err("veuillez entrer une ou plusieurs maps en argument.");
	window->game.board = ft_calloc(size, sizeof(char **));
	while (size > ++i)
		parse_map(&(window->game.board)[i], levels[i], i + 1);
}

int	ft_count_line(int fd)
{
	int	nb;

	nb = 0;
	while (get_next_line(fd) != NULL)
		nb++;
	close(fd);
	return (nb);
}

void	put_new_line(char **source, int fd)
{
	*source = get_next_line(fd);
}

void	parse_map(char ***map, char *level_name, int number_of_level)
{
	int		line;
	int		fd;
	int		i;
	char	*l;

	i = 0;
	fd = open(level_name, O_RDONLY);
	if (fd < 1)
		err("la map n°%d est invalide ou introuvable.", number_of_level);
	line = ft_count_line(open(level_name, O_RDONLY));
	ft_printf("number of lines : %d\n", line);
	*map = ft_calloc(line, sizeof(char *));
	while (i++ < line)
		*map[i] = get_next_line(fd);
}
