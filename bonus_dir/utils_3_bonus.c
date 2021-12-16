/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:02:15 by yeju              #+#    #+#             */
/*   Updated: 2021/09/18 08:02:15 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	reset_sprite(t_data *data, int x, int y)
{
	int	i;

	i = -1;
	while (++i < data->num_collections)
	{
		if (data->sprite[i].x == x && data->sprite[i].y == y)
		{
			data->sprite[i].x = -1000;
			data->sprite[i].y = -1000;
		}
	}
}

void	exit_check(t_data *data)
{
	if (data->map[data->loc_chara.y / 64][data->loc_chara.x / 64] == 'E')
		if (data->get_collections == data->num_collections)
			exit(0);
	if (data->loc_chara.y / 64 == data->enemy.y
		&& data->loc_chara.x / 64 == data->enemy.x)
		exit(0);
}
