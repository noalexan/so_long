/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:17:15 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 18:14:33 by noalexan         ###   ########.fr       */
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

/* ################# PUTS ################# */
void	ft_put_player(t_window *window);
void	ft_fill_floor(t_window *window);
void	ft_put_walls(t_window *win);
void	ft_move(char facing, t_window *window);

int		ft_size_of_tab(char **tab);
int		ft_count_line(int fd);

/* ################# maps ################# */
void	init_map(t_window *window, char **levels);
void	parse_map(char ***map, char *level_name, int number_of_level);

#endif
