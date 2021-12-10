/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:20:02 by rmanuel           #+#    #+#             */
/*   Updated: 2021/12/10 18:18:26 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	init_julia_c(char **str, t_struct *info)
{
	if (info->fractal == 'M')
	{
		info->color = str[2];
		return ;
	}
	else if (info->fractal == 'J')
	{
		info->color = str[3];
		if (str[2][0] == '1')
		{
			info->j_c_re = -0.835;
			info->j_c_im = 0.2321;
		}
		else if (str[2][0] == '2')
		{
			info->j_c_re = 0;
			info->j_c_im = -0.8;
		}
	}
}

void	init_structs(t_struct *info, char **str)
{
	char	*title;

	title = NULL;
	info->fractal = str[1][0];
	if (info->fractal == 'M')
		title = "Mandelbrot";
	else if (info->fractal == 'J')
		title = "Julia";
	info->step = 0.002;
	info->max_im = 1.2;
	info->min_re = -2.0;
	info->mlx_ptr = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx_ptr, X,
			Y, title);
	info->img = mlx_new_image(info->mlx_ptr, X, Y);
	info->addr = mlx_get_data_addr(info->img,
			&info->bits_per_pixel, &info->line_length,
			&info->endian);
	init_julia_c(str, info);
}

void	start_window(t_struct *info)
{
	if (info->fractal == 'M')
		mandelbrot_set(info);
	else if (info->fractal == 'J')
		julia_set(info);
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win,
		info->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_struct	info;

	if (input_validation(argv, argc) == -1)
	{
		validation_fail();
		exit(EXIT_FAILURE);
	}
	init_structs(&info, argv);
	mlx_mouse_hook(info.mlx_win, &mouse_event, &info);
	mlx_key_hook(info.mlx_win, &key_event, &info);
	start_window(&info);
	mlx_loop(info.mlx_ptr);
	exit(EXIT_SUCCESS);
}
