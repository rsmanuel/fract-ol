#include "./includes/fractol.h"

void mlx_pixel_insert(t_data *data, int x, int y, int color)
{
	char *pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void draw_line(t_data *data_img, float beginX, float endX, float beginY, float endY, int color)
{
	float deltaX;
	float deltaY;
	float len;
	float startX;
	float startY;

	// calculalte 2D direction (len X & len Y)
	deltaX = endX - beginX;
	deltaY = endY - beginY;

	// calculate len of line
	len = sqrt((deltaY * deltaY) + (deltaX * deltaX));

	// starting pixels
	startX = beginX;
	startY = beginY;

	// making the distance between pixel_put smaller
	deltaX = deltaX / len;
	deltaY = deltaY / len;

	while (len > 0)
	{
		mlx_pixel_insert(data_img, startX, startY, color);
		startX = startX + deltaX;
		startY = startY + deltaY;
		len--;
	}
}	

void draw_square(t_data *data_img, float beginX, float beginY, float size, int color)
{
	int i;

	i = 0;
	while (i <= size)
	{
		// drawing lines len = beginX + size, with Y + 1 
		draw_line(data_img, beginX, beginX + size, beginY + i, beginY + i, color);
		i++;
	}
}

/*void mandelbrot_set(t_data *data_img, t_struct *info)
{
	double min_re;
	double max_re;
	double min_im;
	double max_im;
	double re_factor;
	double im_factor;
	double c_im;
	double c_re;
	int y;
	int x;

	min_re = -2.0;
	max_re = 1,0;
	min_im = -1,2;
	max_im = min_im + (max_re - min_re) * (info->y / info->x);
	re_factor = (max_re - min_re) / (info->x - 1);
	im_factor = (max_im - min_im) / (info->y - 1);
	y = 0;
	while (y < info->y)
	{
		c_im = max_im - y * im_factor;
		x = 0;
		while (x < info->x)
		{
			c_re = min_re + x * re_factor;

		}
	}

}*/

void mandelbrot_set(t_data *data_img, t_struct *info)
{
	int min_re;
	int max_re;
	int min_im;
	int max_im;
	double a;
	double new_a;
	double temp_a;
	double temp_b;
	double new_b;
	double b;
	int x;
	int y;
	int iterations;

	// scaling between pixel coordinates and complex numbers 
	min_re = -2;
	max_re = 2;
	min_im = -2;
	max_im = 2;
	x = 0;
	y = 0;
	while (x < info->x)
	{
		y = 0;
		while (y < info->y)
		{
			iterations = 0;
			a = min_re + x * (max_re - min_re) / (info->x);
			b = max_im - y * (max_im - min_im) / (info->y);
			temp_a = a;
			temp_b = b;
			while (iterations < 100)
			{
				new_a = (a * a) - (b * b);
				new_b = 2 * a * b;
				a = new_a + temp_a;
				b = new_b + temp_b;
				if (fabs(a + b) > 2)
				{
					break ;
				}
				iterations++;
			}
			if (iterations == 100)
				mlx_pixel_insert(data_img,  x, y, 0xFFFFFF);
			y++;
		}
		x++;
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
