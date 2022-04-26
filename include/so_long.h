/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:17:15 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/26 13:08:26 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# include "structs.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

# define RED_BLOCK_CONSOLE "\033[41m"
# define RESET_CONSOLE_COLOR "\033[0m"

# define RED 0xFF1A2D

void	settings(t_window *window);
void	init_game(t_window *window);
void	stats(t_window *window);

void	game_over(t_window *window);
int		ft_destroy_win(t_window *window);

/* ################# PUTS ################# */
void	ft_put_player(t_window *window);
void	ft_put_health(t_window *window);
void	ft_fill_floor(t_window *window);
void	ft_put_walls(t_window *win, int x, int y);
void	place_objects(t_window *window);
void	ft_move(char facing, t_window *window);

/* ################# UTILS ################ */
int		ft_size_of_tab(char **tab);
int		ft_count_line(int fd);
int		its_a_wall(t_window *window);

/* ################# MAPS ################# */
void	init_map(t_window *window, char **levels);
void	parse_map(t_window *window, char *level_name, int number_of_level);

#endif
