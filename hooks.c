/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:12:21 by rmanuel           #+#    #+#             */
/*   Updated: 2021/12/10 18:14:13 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	zoom(t_struct *info, int button, int x, int y)
{
	double	temp_step;

	if (button == 4)
		temp_step = info->step / 1.05;
	if (button == 5)
		temp_step = info->step * 1.05;
	start_window(info);
}

int	key_event(int button, t_struct *params)
{
	t_struct	*info;

	info = params;
	if (button == 53)
	{
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	mouse_event(int button, int x, int y, t_struct *params)
{
	t_struct	*info;

	info = params;
	if (button == 4 || button == 5)
		zoom(info, button, x, y);
	return (0);
}
