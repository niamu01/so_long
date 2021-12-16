/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:02:02 by yeju              #+#    #+#             */
/*   Updated: 2021/09/18 09:06:18 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**read_map(char *argv)
{
	int		fd;
	char	*tmp;
	int		i;
	char	**p;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		print_error("ERROR\n");
	i = 0;
	while ((get_next_line(fd, &tmp)))
	{
		free(tmp);
		i++;
	}
	free(tmp);
	p = (char **)malloc(sizeof(char *) * (i + 2));
	close(fd);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		print_error("ERROR\n");
	i = 0;
	while ((get_next_line(fd, &p[i])))
		i++;
	p[++i] = 0;
	return (p);
}

void	setting_mlx(t_data *data, t_info info)
{
	data->mlx_ptr = mlx_init();
	data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"tileset.xpm", &data->img.width, &data->img.height);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 64 * info.x,
			64 * info.y, "so_long");
	data->count = 0;
	data->get_collections = 0;
	data->num_collections = 0;
	data->num_start = 0;
	data->num_exit = 0;
	data->image_cake = 0;
}

void	check_walls(t_data *data, t_info info)
{
	int		i;

	i = -1;
	while (++i < info.x)
		if (data->map[0][i] != '1')
			print_error("ERROR\n");
	i = -1;
	while (++i < info.x)
		if (data->map[info.y - 1][i] != '1')
			print_error("ERROR\n");
	i = -1;
	while (++i < info.y)
		if (data->map[i][0] != '1')
			print_error("ERROR\n");
	i = -1;
	while (++i < info.y)
		if (data->map[i][info.x - 1] != '1')
			print_error("ERROR\n");
}

void	check_map_available(t_data *data, t_info info)
{
	check_walls(data, info);
	if (data->num_collections == 0 || data->num_exit == 0 \
		|| data->num_start == 0)
		print_error("ERROR\n");
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_info	info;

	if (argc != 2)
		print_error("ERROR\n");
	data.map = read_map(argv[1]);
	find_info(&info, data.map);
	setting_mlx(&data, info);
	create_map(&data);
	check_map_available(&data, info);
	mlx_hook(data.win_ptr, X_KEY_PRESS, 0, mlx_key_handle, &data);
	mlx_hook(data.win_ptr, X_BUTTON_RED_CROSS, 0, exit_program, 0);
	mlx_loop_hook(data.mlx_ptr, split_animation_1, &data);
	mlx_loop(data.mlx_ptr);
}
