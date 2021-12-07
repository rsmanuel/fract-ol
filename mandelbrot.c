#include "./includes/fractol.h"

int iterate_mandelbrot(double c_re, double c_im)
{
	int iterations;
	double z_re;
	double z_im;
	double tmp_z_re;

	z_re = 0;
	z_im = 0;
	tmp_z_re = 0;
	iterations = 0;
	while (++iterations < MAXITERATIONS)
	{
		tmp_z_re = (z_re * z_re) - (z_im * z_im) + c_re;
		z_im = 2 * (z_re * z_im) + c_im;
		z_re = tmp_z_re;
		if (sqrt(z_re * z_re + z_im * z_im) < 2)
			info->tmp
		if (sqrt(z_re * z_re + z_im * z_im) > 2)
			return(iterations);
	}	

	return (iterations);
}

void mandelbrot_set(t_data *data_img, t_struct *info)
{
	double c_re;
	double c_im;
	double x;
	double y;
	int iterations;

	y = 0;
	info->tmp_iterations = 0;
	while (y < info->y)
	{
		x = 0;
		c_im = MAX_IM - y * STEP;
		while (x < info->x)
		{
			c_re = x * STEP + MIN_RE;
			iterations = iterate_mandelbrot(c_re, c_im);
			info->picked_color = return_colors(iterations, info->color, info);
			mlx_pixel_insert(data_img, x, y, info->picked_color);
			x++;
		}
		y++;
	}
	return ;
}
