/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:38:42 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 14:10:31 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_sprites
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	char	facing;
}			t_sprites;

typedef struct s_player
{
	int			x;
	int			y;
	int			width;
	int			height;
	int			lives;
	t_sprites	sprites;
}			t_player;

typedef struct s_ennemies
{
	int	x;
	int	y;
}			t_ennemies;

typedef struct s_game
{
	int		level;
	int		current_level;
	char	***board;
}			t_game;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_player	player;
	t_game		game;
}			t_window;

#endif
