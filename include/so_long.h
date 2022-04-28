/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:17:15 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 12:22:22 by noalexan         ###   ########.fr       */
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

# define RED_BLOCK_CONSOLE    "\033[41m  \033[0m"
# define GREEN_BLOCK_CONSOLE  "\033[42m  \033[0m"
# define YELLOW_BLOCK_CONSOLE "\033[43m  \033[0m"
# define BLUE_BLOCK_CONSOLE   "\033[44m  \033[0m"
# define PINK_BLOCK_CONSOLE   "\033[45m  \033[0m"
# define CYAN_BLOCK_CONSOLE   "\033[46m  \033[0m"
# define GREY_BLOCK_CONSOLE   "\033[47m  \033[0m"
# define RESET_CONSOLE_COLOR  "\033[0m"
# define VOID_BLOCK_CONSOLE   "  "

# define RED 0xFF1A2D
# define GREEN 0x63F542
# define YELLOW 0xF5FC1C
# define PINK 0xFC1CF1
# define BLUE 0x3D3DFF
# define CYAN 0x3DFFF9
# define ORANGE 0xFFA321

void	settings(t_window *window);
void	init_game(t_window *window);
void	stats(t_window *window);
void	print_nogui_map(t_window *window);

void	end_of_level(t_window *window);
int		ft_destroy_win(t_window *window);

/* ################# PUTS ################# */
void	ft_put_player(t_window *window);
void	ft_put_health(t_window *window);
void	ft_fill_floor(t_window *window);
void	place_objects(t_window *window);
void	ft_move(char facing, t_window *window);
int		animate(t_window *window);

/* ################# UTILS ################ */
int		ft_size_of_tab(char **tab);
int		ft_count_line(int fd);
int		its_a_wall(t_window *window);

/* ################# MAPS ################# */
void	init_map(t_window *window, char **levels);
void	parse_map(t_window *window, char *level_name, int number_of_level);
void	map_is_valid(t_window *window);

#endif
