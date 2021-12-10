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

# define MAXITERATIONS 50
# define X 1900
# define Y 1200

typedef struct s_struct
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	fractal;
	char	*color;
	int 	picked_color;
	double	min_re;
	double	max_im;
	double 	j_c_re;
	double	j_c_im;
	double	step;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_struct;

int		input_validation(char **str, int argc);
void	validation_fail(void);
void	mandelbrot_set(t_struct *info);
void	julia_set(t_struct *info);
void	mlx_pixel_insert(t_struct *info, int x, int y);
int		create_trgb(int t, int r, int g, int b);
int 	return_colors(int iterations, char *color);
int		key_event(int button, t_struct *params);
//int		mouse_event(int button, int x, int y, t_struct *params);
void	start_window(t_struct *info);
int		ft_strcmp(const char *s1, const char *s2);

#endif
