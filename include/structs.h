/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:38:42 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/28 09:48:55 by noalexan         ###   ########.fr       */
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

typedef struct s_color
{
	char	*wall;
	char	*floor;
	char	*player;
	char	*ennemies;
	char	*exit;
	char	*weapons;
	char	*collectibles;
	char	*reset;
	char	*vide;
}			t_color;

typedef struct s_settings
{
	int		max_lives;
	int		live_regain;
	int		speed;
	int		level_title_color;
	int		gameover_title_color;
	int		success_title_color;
	int		nogui;
	t_color	nogui_color;
	char	*dir_path;
	char	*window_title;
	char	*floor;
	char	*wall;
	char	*player[4];
	char	*health[2];
	char	*door[2];
}			t_settings;

typedef struct s_player
{
	int			x;
	int			y;
	int			width;
	int			height;
	int			lives;
	t_sprites	sprites;
}			t_player;

typedef struct s_collectibles
{
	int	taken;
}			t_collectibles;

typedef struct s_ennemies
{
	int	x;
	int	y;
}			t_ennemies;

typedef struct s_map
{
	char	*level_name;
	int		width;
	int		heigth;
	int		x_pos;
	int		y_pos;
	char	**board;
}			t_map;

typedef struct s_game
{
	int		level;
	int		current_level;
	int		exit;
	t_map	*maps;
}			t_game;

typedef struct s_window
{
	void			*mlx;
	void			*win;
	t_settings		settings;
	t_ennemies		*ennemies;
	t_collectibles	*collectibles;
	t_player		player;
	t_game			game;
}			t_window;

#endif
