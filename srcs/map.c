/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:06:58 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 09:59:49 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	size_of_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_count_line(int fd)
{
	int		nb;
	char	*line;

	nb = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		nb++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (nb);
}

int	calc_size_of_line(int fd)
{
	char	*line;
	int		size_l;
	int		old;

	line = get_next_line(fd);
	size_l = ft_strlen(line);
	while (line != NULL)
	{
		old = size_l;
		size_l = ft_strlen(line);
		if (old != size_l)
			return (-1);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (size_l);
}

void	parse_map(t_window *window, char *level_name, int level_num)
{
	int		fd;
	int		size;
	int		size_l;
	int		i;

	i = -1;
	fd = open(level_name, O_RDONLY);
	if (fd < 3)
		err("impossible d'ouvrir la map '%s'.", level_name);
	size = ft_count_line(open(level_name, O_RDONLY));
	size_l = calc_size_of_line(open(level_name, O_RDONLY));
	if (size_l < 3 || size < 3)
		err("la map '%s' est invalide.", level_name);
	if (ft_strcmp(".ber", level_name + (ft_strlen(level_name) - 4)) != 0)
		err("la map '%s' n'est pas un fichier ber.", level_name);
	window->game.maps[level_num].heigth = size * 16;
	window->game.maps[level_num].width = size_l * 16;
	window->game.maps[level_num].level_name = level_name;
	window->game.maps[level_num].board = ft_calloc(size + 1, sizeof(char *));
	while (++i < size)
		window->game.maps[level_num].board[i] = get_next_line(fd);
	close(fd);
}

void	init_map(t_window *window, char **levels)
{
	int	size;
	int	i;

	size = size_of_tab((void *) levels);
	if (size < 1)
		err("veuillez entrer une ou plusieurs maps en argument.");
	if (!ft_strcmp(levels[size - 1], "--nogui"))
	{
		window->settings.nogui = 1;
		size--;
	}
	window->game.level = size;
	window->game.current_level = -1;
	window->game.maps = ft_calloc(size, sizeof(t_map));
	i = -1;
	while (++i < size)
		parse_map(window, levels[i], i);
	map_is_valid(window);
}
