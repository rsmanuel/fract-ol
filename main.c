/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:20:02 by rmanuel           #+#    #+#             */
/*   Updated: 2021/11/10 11:57:59 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	start_window(t_struct *info, t_data *data_img, char **argv)
{
	info->mlx_ptr = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx_ptr, info->x,
			info->y, argv[1]);
	data_img->img = mlx_new_image(info->mlx_ptr, info->x, info->y);
	data_img->addr = mlx_get_data_addr(data_img->img,
			&data_img->bits_per_pixel, &data_img->line_length,
			&data_img->endian);
	mandelbrot_set(data_img, info);
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win,
		data_img->img, 0, 0);
	mlx_loop(info->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_struct	*info;
	t_data		*data_img;
	int			validation;

	info = malloc(sizeof(t_struct));
	data_img = malloc(sizeof(t_data));
	validation = input_validation(argv, argc, info);
	if (validation == 1)
	{
		start_window(info, data_img, argv);
		free(info);
		free(data_img);
		exit(EXIT_SUCCESS);
	}
	else if (validation == -1)
	{
		validation_fail();
		free(info);
		free(data_img);
		exit(EXIT_FAILURE);
	}
}
