#include "./includes/fractol.h"

void mlx_pixel_insert(t_data *data, int x, int y, int color)
{
	char *pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void mandelbrot_set(t_data *data_img, t_struct *info)
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
					mlx_pixel_insert(data_img, x, y, create_trgb(0, 5 * (n),
							3 * (n) + 50, 0.2 * (n + 2)));
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
}

int main(int argc, char **argv)
{
	t_struct *info;
	t_data *data_img;
	int validation;

	info = malloc(sizeof(t_struct));
	data_img = malloc(sizeof(t_data));
	validation = input_validation(argv, argc, info);
	if (validation == 1)
	{
		info->mlx_ptr = mlx_init();
		info->mlx_win = mlx_new_window(info->mlx_ptr, info->x, info->y, argv[1]);
		data_img->img = mlx_new_image(info->mlx_ptr, info->x, info->y);
		data_img->addr = mlx_get_data_addr(data_img->img, &data_img->bits_per_pixel, &data_img->line_length, &data_img->endian);
		mandelbrot_set(data_img, info);
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, data_img->img, 0, 0);
		mlx_loop(info->mlx_ptr);
	}
	else if (validation == -1)
	{
		validation_fail();
		free(info);
		free(data_img);
		exit(EXIT_FAILURE);
	}
}
