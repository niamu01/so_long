/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 06:24:56 by yeju              #+#    #+#             */
/*   Updated: 2021/09/18 06:24:57 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	t_location	loc_chara;
	t_img		img;
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

#endif