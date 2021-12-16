/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:02:13 by yeju              #+#    #+#             */
/*   Updated: 2021/09/18 09:05:35 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_wall(t_data *data, int add_x, int add_y)
{
	int	x;
	int	y;

	x = (data->loc_chara.x + add_x) / 64;
	y = (data->loc_chara.y + add_y) / 64;
	if (data->map[y][x] == '1')
		return (1);
	return (0);
}

int	check_if_collection(t_data *data, int add_x, int add_y)
{
	int	x;
	int	y;

	x = (data->loc_chara.x + add_x) / 64;
	y = (data->loc_chara.y + add_y) / 64;
	if (data->map[y][x] == 'C')
	{
		data->get_collections++;
		return (1);
	}
	return (0);
}

int	mlx_key_handle(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 53)
		return (exit_program());
	else if (keycode == 0)
		return (move_left(data));
	else if (keycode == 2)
		return (move_right(data));
	else if (keycode == 1)
		return (move_down(data));
	else if (keycode == 13)
		return (move_up(data));
	return (0);
}

void	find_info(t_info *info, char **p)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = 0;
	while (p[0][x])
		x++;
	y = 0;
	while (p[y])
		y++;
	i = -1;
	info->x = x;
	info->y = y;
	while (++i < y)
	{
		j = -1;
		while (p[i][++j])
			if (j > x)
				print_error("ERROR\n");
	}
}

void	check_move(t_data *data)
{
	t_info	info;
	int		i;
	int		j;

	find_info(&info, data->map);
	i = -1;
	while (++i < info.y)
	{
		j = -1;
		while (++j < info.x)
			map_color(data, i, j);
	}
	show_enemy(data);
	if (data->map[data->loc_chara.y / 64][data->loc_chara.x / 64] == 'C')
	{
		data->map[data->loc_chara.y / 64][data->loc_chara.x / 64] = '0';
		reset_sprite(data, data->loc_chara.x / 64, data->loc_chara.y / 64);
		check_move(data);
		data->get_collections++;
	}
	exit_check(data);
}
