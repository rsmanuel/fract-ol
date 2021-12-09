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

void julia_set(t_data *data_img, t_struct *info)
{
    double z_re;
	double z_im;
	double x;
	double y;
	int iterations;

	y = 0;
	while (y < info->y)
	{
		x = 0;
		z_im = MAX_IM - y * STEP;
		while (x < info->x)
		{
			z_re = x * STEP + MIN_RE;
			iterations = iterate_julia(z_re, z_im, -0.232 , -0.684);
			info->picked_color = return_colors(iterations, info->color);
			mlx_pixel_insert(data_img, x, y, info->picked_color);
			x++;
		}
		y++;
	}
}