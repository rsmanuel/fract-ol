/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:44:50 by rmanuel           #+#    #+#             */
/*   Updated: 2021/11/10 17:44:17 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include	"../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define MIN_RE	-2.0
# define MAX_IM 1.2
# define STEP 0.002
# define MAXITERATIONS 50

typedef struct s_struct
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		x;
	int		y;
	char	*fractal;
	char	*color;
	int 	picked_color;
	int		precision;
}	t_struct;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int		input_validation(char **str, int argc, t_struct *info);
void	validation_fail(void);
void	mandelbrot_set(t_data *data_img, t_struct *info);
void	mlx_pixel_insert(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int 	return_colors(int iterations, char *color);

#endif
