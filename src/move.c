/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 06:24:24 by yeju              #+#    #+#             */
/*   Updated: 2021/09/18 06:24:25 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_data *data)
{
	if (check_wall(data, -64, 0))
		return (0);
	data->loc_chara.x -= 64;
	check_move(data);
	put_character(data->mlx_ptr, data->win_ptr,
		data->loc_chara.x, data->loc_chara.y);
	data->count++;
	print_count(data->count);
	return (0);
}

int	move_right(t_data *data)
{
	if (check_wall(data, 64, 0))
		return (0);
	data->loc_chara.x += 64;
	check_move(data);
	put_character(data->mlx_ptr, data->win_ptr,
		data->loc_chara.x, data->loc_chara.y);
	data->count++;
	print_count(data->count);
	return (0);
}

int	move_down(t_data *data)
{
	if (check_wall(data, 0, 64))
		return (0);
	data->loc_chara.y += 64;
	check_move(data);
	put_character(data->mlx_ptr, data->win_ptr,
		data->loc_chara.x, data->loc_chara.y);
	data->count++;
	print_count(data->count);
	return (0);
}

int	move_up(t_data *data)
{
	if (check_wall(data, 0, -64))
		return (0);
	data->loc_chara.y -= 64;
	check_move(data);
	put_character(data->mlx_ptr, data->win_ptr,
		data->loc_chara.x, data->loc_chara.y);
	data->count++;
	print_count(data->count);
	return (0);
}
