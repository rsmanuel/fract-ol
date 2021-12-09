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

void	mlx_pixel_insert(t_struct *info, int x, int y)
{
	char	*pixel;
	int		color;

	color = info->picked_color;
	pixel = info->addr + (y * info->line_length
			+ x * (info->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}


int return_colors(int iterations, char *color)
{
	if (iterations == MAXITERATIONS)
		return (0);
	if (!ft_strncmp(color, "red", 3))
		return(create_trgb(0, 6 * iterations , 0, 0));
	else if (!ft_strncmp(color, "green", 5))
		return(create_trgb(0, 0, 6 * iterations, 0));
	else if (!ft_strncmp(color, "blue", 4))
		return(create_trgb(0, 0, 0,  6 * iterations));

	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
