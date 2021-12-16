/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:02:17 by yeju              #+#    #+#             */
/*   Updated: 2021/09/18 08:05:17 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_count(int count)
{
	char	*str;

	str = ft_itoa(count);
	write(1, "count: ", 8);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

int	exit_program(void)
{
	exit(0);
	return (0);
}

void	map_color(t_data *data, int i, int j)
{
	if (data->map[i][j] == '0' || data->map[i][j] == 'P')
		mlx_put_image_to_window_scale(data->mlx_ptr, data->win_ptr,
			data->img_ptr, 32, 64, 32, 32, 64 * j, 64 * i, 65, 65, 0x00d942);
	else if (data->map[i][j] == '1')
		mlx_put_image_to_window_scale(data->mlx_ptr, data->win_ptr,
			data->img_ptr, 32, 64, 32, 32, 64 * j, 64 * i, 65, 65, 0x000000);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window_scale(data->mlx_ptr, data->win_ptr,
			data->img_ptr, 32, 64, 32, 32, 64 * j, 64 * i, 65, 65, 0x0000ff);
}
