#include "./includes/fractol.h"

/*void mandelbrot_set(t_data *data_img, t_struct *info)
{
	int x;
	int y;
	double MAX_IM;
	double c_re;
	double c_im;
	double z_im;
	double z_re;
	double temp_z_re;
	double temp_z_im;
	int isInside;
	int n;

	MAX_IM = MIN_IM + (MAX_RE - MIN_RE) * info->y / info->x;
	x = 0;
	y = 0;
	n = 0;
	isInside = 0;
	while (y < info->y)
	{
		x = 0;
		c_im = MAX_IM - y * (MAX_IM - MIN_IM) / (info->y - 1);
		while (x < info->x)
		{
			c_re = MIN_RE + x * (MAX_RE - MIN_RE) / (info->x - 1);
			z_re = c_re;
			z_im = c_im;
			n = 0;
			while (n < MAXITERATIONS)
			{
				isInside = 1;
				temp_z_re = z_re * z_re;
				temp_z_im = z_im * z_im;
				if ((temp_z_re + temp_z_im) > 4.000000)
				{
					if (n >= 0 && n <= MAXITERATIONS / 2 - 1)
						mlx_pixel_insert(data_img, x, y, create_trgb(0, 1 * (n), 0.2 * (n), 0.2 + 10 * (n)));
					else
						mlx_pixel_insert(data_img, x, y, create_trgb(0, 1 - 5 * (n), 5 + 10 * (n), 3 + 5 * (n)));
					isInside = 0;
					break ;
				}
				z_im = 2 * z_re * z_im + c_im;
				z_re = temp_z_re - temp_z_im + c_re;
				n++;
			}
			if (isInside == 1)
			{
				mlx_pixel_insert(data_img, x, y, 0x000000);
			}
			x++;
		}
		y++;
	}
}*/

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
	while (y < info->y)
	{
		x = 0;
		c_im = MAX_IM - y * STEP;
		while (x < info->x)
		{
			c_re = x * STEP + MIN_RE;
			iterations = iterate_mandelbrot(c_re, c_im);
			if(iterations == MAXITERATIONS)
				mlx_pixel_insert(data_img, x, y, 0);
			else 
			{
				info->picked_color = return_colors(iterations, info->color);
				mlx_pixel_insert(data_img, x, y, info->picked_color);
			}
			x++;
		}
		y++;
	}
}
