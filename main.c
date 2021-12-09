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

int key_event(int button, t_struct *params)
{
	t_struct *info = params;
	if (button == 53)
	{
		mlx_destroy_image(info->mlx_ptr, info->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	start_window(t_struct *info, char **argv)
{
	info->mlx_ptr = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx_ptr, X,
			Y, argv[1]);
	info->img = mlx_new_image(info->mlx_ptr, X, Y);
	info->addr = mlx_get_data_addr(info->img,
			&info->bits_per_pixel, &info->line_length,
			&info->endian);
	mandelbrot_set(info);
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win,
		info->img, 0, 0);
	mlx_key_hook(info->mlx_win, &key_event, info);
	mlx_loop(info->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_struct	info;
	int			validation;
	;
	validation = input_validation(argv, argc, &info);
	if (validation == 1)
	{
		start_window(&info, argv);
		exit(EXIT_SUCCESS);
	}
	else if (validation == -1)
	{
		validation_fail();
		exit(EXIT_FAILURE);
	}
}
