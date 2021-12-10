#include "./includes/fractol.h"

int iterate_julia(double z_re, double z_im, double c_re, double c_im)
{
    int iterations;
	double tmp_z_re;

	tmp_z_re = 0;
	iterations = 0;
	while (++iterations < MAXITERATIONS)
	{
		tmp_z_re = (z_re * z_re) - (z_im * z_im) + c_re;
		z_im = 2 * (z_re * z_im) + c_im;
		z_re = tmp_z_re;
		if (sqrt(z_re * z_re + z_im * z_im) > 2)
			return(iterations);
	}	

	return (iterations);
}

void julia_set(t_struct *info)
{
    double z_re;
	double z_im;
	double x;
	double y;
	int iterations;

	y = 0;
	while (y < Y)
	{
		x = 0;
		z_im = info->max_im - y * info->step;
		while (x < X)
		{
			z_re = x * info->step + info->min_re;
			iterations = iterate_julia(z_re, z_im, info->j_c_re, info->j_c_im);
			info->picked_color = return_colors(iterations, info->color);
			mlx_pixel_insert(info, x, y);
			x++;
		}
		y++;
	}
}
