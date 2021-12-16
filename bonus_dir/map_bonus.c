/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:02:04 by yeju              #+#    #+#             */
/*   Updated: 2021/09/18 08:04:59 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_collection(void *mlx_ptr, void *win_ptr, int x, int y)
{
	void	*img_ptr;
	int		img_width;
	int		img_height;

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./cake.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window_scale(mlx_ptr, win_ptr, img_ptr, 64, 0,
		32, 32, x, y, 64, 64, 0xFFFFFFFF);
}

void	put_character(void *mlx_ptr, void *win_ptr, int x, int y)
{
	void	*img_ptr;
	int		img_width;
	int		img_height;

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./character.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window_scale(mlx_ptr, win_ptr, img_ptr, 0, 0,
		48, 48, x, y, 64, 64, 0xFFFFFFFF);
}

void	player_color(t_data *data, int i, int j)
{
	data->loc_chara.x = 64 * j;
	data->loc_chara.y = 64 * i;
	data->num_start++;
	mlx_put_image_to_window_scale(data->mlx_ptr, data->win_ptr, data->img_ptr,
		32, 64, 32, 32, 64 * j, 64 * i, 65, 65, 0x00d942);
	put_character(data->mlx_ptr, data->win_ptr, 64 * j, 64 * i);
}

void	element_color(t_data *data, int i, int j)
{
	if (data->map[i][j] == '0')
		mlx_put_image_to_window_scale(data->mlx_ptr, data->win_ptr,
			data->img_ptr, 32, 64, 32, 32, 64 * j, 64 * i, 65, 65, 0x00d942);
	else if (data->map[i][j] == '1')
		mlx_put_image_to_window_scale(data->mlx_ptr, data->win_ptr,
			data->img_ptr, 32, 64, 32, 32, 64 * j, 64 * i, 65, 65, 0x000000);
	else if (data->map[i][j] == 'C')
	{
		mlx_put_image_to_window_scale(data->mlx_ptr, data->win_ptr,
			data->img_ptr, 32, 64, 32, 32, 64 * j, 64 * i, 65, 65, 0x00d942);
		put_collection(data->mlx_ptr, data->win_ptr, 64 * j, 64 * i);
		data->num_collections++;
	}
	else if (data->map[i][j] == 'E')
	{
		mlx_put_image_to_window_scale(data->mlx_ptr, data->win_ptr,
			data->img_ptr, 32, 64, 32, 32, 64 * j, 64 * i, 65, 65, 0x0000ff);
		data->num_exit++;
	}
	else if (data->map[i][j] == 'P')
		player_color(data, i, j);
}

void	create_map(t_data *data)
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
			element_color(data, i, j);
	}
	data->sprite = (t_sprite *)malloc(sizeof(t_sprite) * data->num_collections);
	data->get_sprite = 0;
	i = -1;
	while (++i < info.y)
	{
		j = -1;
		while (++j < info.x)
			insert_sprite_array(data, i, j);
	}
	count_and_enemy(data, info);
}
