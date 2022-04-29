/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:26:53 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/29 14:17:54 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_window *window)
{
	int	i;

	i = -1;
	mlx_clear_window(window->mlx, window->win);
	ft_fill_floor(window);
	place_objects(window);
	ft_put_player(window);
	while (++i < window->game.maps[window->game.current_level]
		.nb_of_ennemies)
		ft_put_ennemies(window, i);
	print_level(window);
	ft_put_health(window);
	stats(window);
}

void	print_count(t_window *window)
{
	char	*count;

	count = ft_itoa(window->game.maps[window->game.current_level].count);
	mlx_string_put(window->mlx, window->win, 2, -2,
		mlx_get_color_value(window->mlx, window->settings.count_color),
		count);
	free(count);
}

void	print_level(t_window *window)
{
	char	*level;
	char	*nb;
	void	*im;
	int		w;
	int		h;

	im = mlx_xpm_file_to_image(window->mlx, window->settings.weapon[0], &w, &h);
	nb = ft_itoa(window->game.current_level + 1);
	level = ft_strjoin("Level ", nb);
	free(nb);
	mlx_string_put(window->mlx, window->win, 2, -2,
		mlx_get_color_value(window->mlx, window->settings.level_title_color),
		level);
	free(level);
	if (window->player.armed)
		mlx_put_image_to_window(window->mlx, window->win, im, 100, 2);
}
