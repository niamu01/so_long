/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:02:10 by yeju              #+#    #+#             */
/*   Updated: 2021/09/18 08:02:11 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ani_sub(t_data *data, void *img_ptr1, void *img_ptr2, int i)
{
	if (data->image_cake < 50)
		mlx_put_image_to_window_scale(data->mlx_ptr, data->win_ptr, img_ptr1,
			0, 0, 32, 32, 64 * data->sprite[i].x,
			64 * data->sprite[i].y, 64, 64, 0xFFFFFFFF);
	else
		mlx_put_image_to_window_scale(data->mlx_ptr, data->win_ptr, img_ptr2,
			0, 0, 32, 32, 64 * data->sprite[i].x,
			64 * data->sprite[i].y, 64, 64, 0xFFFFFFFF);
}

int	split_animation_1(t_data *data)
{
	void	*img_ptr1;
	void	*img_ptr2;
	int		img_width1;
	int		img_height1;
	int		i;

	img_ptr1 = mlx_xpm_file_to_image(data->mlx_ptr, "./cake.xpm",
			&img_width1, &img_height1);
	img_ptr2 = mlx_xpm_file_to_image(data->mlx_ptr, "./cake2.xpm",
			&img_width1, &img_height1);
	i = -1;
	while (++i < data->num_collections)
		ani_sub(data, img_ptr1, img_ptr2, i);
	data->image_cake++;
	if (data->image_cake == 100)
		data->image_cake = 0;
	return (0);
}

void	insert_sprite_array(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'C')
	{
		data->sprite[data->get_sprite].x = j;
		data->sprite[data->get_sprite].y = i;
		data->get_sprite++;
	}
}

void	show_enemy(t_data *data)
{
	void	*img_ptr;
	int		img_width;
	int		img_height;

	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./enemy.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window_scale(data->mlx_ptr, data->win_ptr, img_ptr, 64, 0,
		32, 32, data->enemy.x * 64, data->enemy.y * 64, 64, 64, 0xFFFFFFFF);
}

void	count_and_enemy(t_data *data, t_info info)
{
	char	*str;

	str = ft_itoa(data->count);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 32, 32, 0xFFFFFF, str);
	free(str);
	srand(time(NULL));
	while (1)
	{
		data->enemy.x = rand() % info.x;
		data->enemy.y = rand() % info.y;
		if (data->map[data->enemy.y][data->enemy.x] == '0')
			break ;
	}
	show_enemy(data);
}
