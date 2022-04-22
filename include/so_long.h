/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:17:15 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/22 12:40:25 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>

# include "structs.h"

void	ft_put_player(t_window *window);
void	ft_fill_floor(t_window *window);
void	ft_put_walls(t_window *win);
void	ft_move(char facing, t_window *window);

#endif
