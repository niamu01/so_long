/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:02:08 by yeju              #+#    #+#             */
/*   Updated: 2021/09/18 08:02:09 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "./get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# define X_KEY_PRESS 2
# define X_KEY_RELEASE 3
# define X_BUTTON_RED_CROSS 17
# define X_BUTTON_LEFT 123
# define X_BUTTON_RIGHT 124
# define X_BUTTON_DOWN 125
# define X_BUTTON_UP 126

typedef struct s_info{
	int		x;
	int		y;
}	t_info;

typedef struct s_location{
	int		x;
	int		y;
}	t_location;

typedef struct s_img{
	int		width;
	int		height;
}	t_img;

typedef struct s_sprite{
	int		x;
	int		y;
}	t_sprite;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		**map;
	int			count;
	int			num_exit;
	int			num_start;
	int			num_collections;
	int			get_collections;
	int			get_sprite;
	long		image_cake;
	t_location	loc_chara;
	t_location	enemy;
	t_img		img;
	t_sprite	*sprite;
}	t_data;

int		move_left(t_data *data);
int		move_right(t_data *data);
int		move_down(t_data *data);
int		move_up(t_data *data);

void	print_error(char *str);
int		ft_strlen(char *str);
void	print_count(int count);
int		exit_program(void);
void	map_color(t_data *data, int i, int j);

int		check_wall(t_data *data, int add_x, int add_y);
int		check_if_collection(t_data *data, int add_x, int add_y);
int		mlx_key_handle(int keycode, void *param);
void	find_info(t_info *info, char **p);
void	check_move(t_data *data);

void	put_collection(void *mlx_ptr, void *win_ptr, int x, int y);
void	put_character(void *mlx_ptr, void *win_ptr, int x, int y);
void	player_color(t_data *data, int i, int j);
void	element_color(t_data *data, int i, int j);
void	create_map(t_data *data);

char	*ft_itoa(int n);

void	ani_sub(t_data *data, void *img_ptr1, void *img_ptr2, int i);
int		split_animation_1(t_data *data);
void	insert_sprite_array(t_data *data, int i, int j);
void	show_enemy(t_data *data);
void	count_and_enemy(t_data *data, t_info info);

void	reset_sprite(t_data *data, int x, int y);
void	exit_check(t_data *data);

#endif