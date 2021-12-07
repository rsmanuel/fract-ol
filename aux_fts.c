/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:35:59 by rmanuel           #+#    #+#             */
/*   Updated: 2021/11/10 17:35:02 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/fractol.h"

void	mlx_pixel_insert(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}


int return_colors(int iterations, char *color, t_struct *info)
{
	if (!ft_strncmp(color, "red", 3))
		return(create_trgb(0, 5.1 * iterations , 0, 0));
	else if (!ft_strncmp(color, "green", 5))
		return(create_trgb(0, 0, 5.1 * iterations, 0));
	else if (!ft_strncmp(color, "blue", 4))
	{
		if (iterations == MAXITERATIONS)
		{
			printf("%d\n", info->tmp_iterations);
			return(create_trgb(info->tmp_iterations, 0, 255, 0));
		}
		else
		{
			return(create_trgb(0, 0, 0, 255 - iterations * 10));
		}
	}
	else if (!ft_strncmp(color, "crazy", 5))
	{
		if (iterations > 0 && iterations <= 12)
			return(create_trgb(0, 252 + ((252 - 252) / 11) * iterations , 98 + ((243 - 98) / 11) * iterations, 64 + ((64 - 64) / 11) * iterations));
		else if (iterations > 12 && iterations <= 25)
			return(create_trgb(0, 127 + ((234 - 127) / 12) * iterations , 255 + ((255 - 255) / 12) * iterations, 0));
		else if (iterations > 25 && iterations <= 38)
			return(create_trgb(0, 251 + ((128 - 251) / 12) * iterations , 51 + ((51 - 51) / 12) * iterations, 219 + ((251 - 219) / 12) * iterations));
		else if (iterations > 38  && iterations < 50)
			return(create_trgb(0, 3 + ((3 - 3) / 10) * iterations , 16 + ((226 - 16) / 10) * iterations, 234 + ((234 - 234) / 10) * iterations));
	}
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
